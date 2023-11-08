#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;

//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  set<T> s;
  T *arr = new T[mSize]();
  size_t arrind=0;
  size_t newsize=0;
  for(int i=0;i<mSize;i++){
    if(s.find(mData[i])==s.end()){
      arr[arrind] = mData[i];
      newsize++;
      arrind++;
    }
    s.insert(mData[i]);
  }
  delete [] mData;
  mData = arr;
  mSize = newsize;
  mCap = mSize;
}

#endif
