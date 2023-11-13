#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  if(k==1){
    return mData[0];
  }if(k==2){
    if(mLess(mData[1],mData[2])){
      return mData[2];
    }else{
      return mData[1];
    }
  }else{
    if(mLess(mData[2],mData[1])){
      if(mLess(mData[3],mData[2]) && mLess(mData[4], mData[2])){
        return mData[2];
      }
      else if(mLess(mData[2], mData[3]) && mLess(mData[4], mData[3])){
        return mData[3];
      }
      else{
        return mData[4];
      }
    }
    else if(mLess(mData[1],mData[2])){
      if(mLess(mData[5],mData[1]) && mLess(mData[6], mData[1])){
        return mData[1];
      }
      else if(mLess(mData[1], mData[5]) && mLess(mData[6], mData[5])){
        return mData[5];
      }
      else{
        return mData[6];
      }
    }
  }
}

#endif
