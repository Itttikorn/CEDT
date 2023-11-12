#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    if(pos>=mSize){
        return;
    }
    T tmp = mData[mFront];
    mData[mFront] = mData[(mFront+pos)%mCap];
    for(int i=mFront+1;i<=mFront+pos;i++){
        T temp = mData[i%mCap];
        mData[i%mCap] = tmp;
        tmp = temp;
    }
}

#endif
