#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  T *arr = new T[mSize+data.size()]();
  int newarrind=0,dataind=0;
  std::sort(data.begin(),data.end());

  for(int i=0;i<mSize;i++){
    if(data[dataind].first == i){
      arr[newarrind] = data[dataind].second;
      dataind++;
      newarrind++;
    }
    arr[newarrind] = mData[i];
    newarrind++;
  }
  if(data[dataind].first == mSize){
    arr[newarrind] = data[dataind].second;
  }
  delete [] mData;
  mData = arr;
  mSize = mSize+data.size();
  mCap = mSize;
}

#endif
