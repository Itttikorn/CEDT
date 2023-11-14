#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for(auto itr = ls.begin();itr!=ls.end();itr++){
    CP::list<T>& thislist = *itr;
    mHeader->prev->next = thislist.mHeader->next;
    thislist.mHeader->next->prev = mHeader->prev;
    thislist.mHeader->prev->next = mHeader;
    mHeader->prev = thislist.mHeader->prev;
    thislist.mHeader->next = thislist.mHeader;
    thislist.mHeader->prev = thislist.mHeader;
    mSize+=thislist.size();
    thislist.mSize=0;
  }

}

#endif
