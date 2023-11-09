#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if(m==0){
    return false;
  }
  int vsize = end()-begin()-1;
  int aloc = a-begin();
  int bloc = b-begin();
  auto aend = a;
  auto bend = b;
  for(size_t i=0;i<m-1;i++){
    aend++;
    bend++;
  }
  int aloc2 = aend-begin();
  int bloc2 = bend-begin();
  if(bloc<aloc){
    int tmploc = aloc;
    int tmploc2 = bloc;
    aloc = bloc;
    aloc2 = bloc2;
    bloc = tmploc;
    bloc2 = tmploc2;
  }
  //std::cout << aloc << " " << bloc << " " << aloc2 << " " << bloc2 << std::endl;
  if(aloc<0 || aloc>vsize || bloc<0 || bloc>vsize || aloc2<0 || aloc2>vsize || bloc2<0 || bloc2>vsize || bloc <= aloc2){
    return false;
  }else{
    for(int i=0;i<m;i++){
      int tmp = *a;
      *a = *b;
      *b = tmp;
      a++;
      b++;
    }
    return true;
  }
}

#endif
