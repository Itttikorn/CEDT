void replace(const T& x, list<T>& y) {
  //write your code here
  auto itr = begin();
  while(itr!=end()){
    if(*itr==x){
      itr = erase(itr);
      auto jtr = y.begin();
      while(jtr!=y.end()){
        insert(itr,*jtr);
        jtr++;
      }
    }else{
      itr++;
    }
  }
}
