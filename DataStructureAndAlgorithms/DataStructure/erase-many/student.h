#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  auto itr = pos.begin();
  int i=0;
  for(auto itr=pos.begin();itr!=pos.end();itr++){
    auto it = begin()+*itr-i;
    while((it+1)!=end()) {
        *it = *(it+1);
        it++;
      }
      mSize--;
    i++;
  }
}

#endif
