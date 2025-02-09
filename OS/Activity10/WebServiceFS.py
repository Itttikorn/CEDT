#!/usr/bin/env python3

# 2110352 Operating System
# FUSE/Filesystem exercise
# By Krerk Piromsopa, Ph.D. <Krerk.P@chula.ac.th>
#    Department of Computer Engineering
#    Chulalongkorn University.

import os, stat, errno
import fuse
import requests
from fuse import Fuse

if not hasattr(fuse, '__version__'):
    raise RuntimeError("your fuse-py doesn't know of fuse.__version__, probably it's too old.")

fuse.fuse_python_api = (0, 2)

containers={ \
		'/participation':b" ",
	}

class MyStat(fuse.Stat):
    def __init__(self):
        self.st_mode = 0
        self.st_ino = 0
        self.st_dev = 0
        self.st_nlink = 0
        self.st_uid = 0
        self.st_gid = 0
        self.st_size = 0
        self.st_atime = 0
        self.st_mtime = 0
        self.st_ctime = 0

class MyFS(Fuse):

    def getattr(self, path):
        st = MyStat()
        if path == '/':
            st.st_mode = stat.S_IFDIR | 0o777
            st.st_nlink = 2
        elif path in containers:
            st.st_mode = stat.S_IFREG | 0o777
            st.st_nlink = 1
            content=containers[path]
            st.st_size = len(content)
        else:
            return -errno.ENOENT
        return st

    def readdir(self, path, offset):
        filenames=containers.keys()
        for r in  '.', '..':
            yield fuse.Direntry(r)

        for r in filenames:
            yield fuse.Direntry(r[1:])


    def open(self, path, flags):
        if path not in containers:
            return -errno.ENOENT
        accmode = os.O_RDONLY | os.O_WRONLY | os.O_RDWR
        if (flags & accmode) not in (os.O_RDONLY, os.O_WRONLY, os.O_RDWR):
            return -errno.EACCES

    def read(self, path, size, offset):
        if path not in containers:
            return -errno.ENOENT
        if path == '/participation':
            req = requests.get('https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/status.php')
            res = bytes(req.text, 'utf-8')
            containers[path] = res   
        content = containers[path]
        slen = len(content)
        if offset < slen:
            if offset + size > slen:
                size = slen - offset
            buf = content[offset:offset+size]
        else:
            buf = ''
        return buf
    
    def write(self, path, buf, offset):
        if path == '/participation':
            raw = buf.decode('utf-8').strip().split(':')
            if len(raw) != 3:
                return -errno.EINVAL
            checkInUrl = 'https://mis.cp.eng.chula.ac.th/krerk/teaching/2022s2-os/checkIn.php'
            parms = {'studentid': raw[0], 'name': raw[1], 'email': raw[2]}
            response = requests.post(checkInUrl, data=parms)
            if response.status_code == 200:
                containers[path] = containers[path][:offset] + buf + containers[path][offset+len(buf):]
                return len(buf)
            else:
                return -errno.EIO
        return -errno.ENOENT

def main():
    usage="""
MyFS mounting_point

""" + Fuse.fusage
    server = MyFS(version="%prog " + fuse.__version__,
                     usage=usage,
                     dash_s_do='setsingle')

    server.parse(errex=1)
    server.main()

if __name__ == '__main__':
    main()
