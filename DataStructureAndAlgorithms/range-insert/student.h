#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  size_t backsize = end()-position;
  T *arr = new T[backsize]();
  int count=0;
  for(auto itr = position;itr!=end();itr++){
    //printf("%d\n",*itr);
    arr[count] = *itr;
    count++;
  }
  mSize = mSize-backsize;
  for(auto itr=first;itr!=last;itr++){
    //printf("%d\n",*itr);
    push_back(*itr);
  }
  for(int i=0;i<count;i++){
    //printf("%d %d\n",count,arr[i]);
    push_back(arr[i]);
  }
  delete [] arr;
}

#endif
