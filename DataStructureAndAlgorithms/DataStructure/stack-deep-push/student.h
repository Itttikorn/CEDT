#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  if(pos==0){
    push(value);
    return;
  }
  ensureCapacity(mSize+1);
  mSize++;
  for(int i=mSize;i>=mSize-pos;i--){
    mData[i] = mData[i-1];
  }
  mData[mSize-pos-1] = value;
}

#endif
