#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node *n = mRoot;
  node *m = result.mRoot;
  node *nr = mRoot;
  bool foundfirst=false;
  bool foundoldfirst=false;
  while(n!=NULL){
   if(!mLess(n->data.first,val)){
    if(!foundfirst){
      result.mRoot = n;
      m = n;
      m->parent = NULL;
      foundfirst = true;
    }else{
      m->left = n;
      m->left->parent = m;
      m = m->left;
    }
    node *tmp = n->left;
    n->left = NULL;
    n = tmp;
   }else{
    if(!foundoldfirst){
      mRoot = n;
      nr = mRoot;
      nr->parent = NULL;
      foundoldfirst = true;
    }else{
      nr->right = n;
      nr->right->parent = nr;
      nr = nr->right;
    }
    node *tmp = n->right;
    n->right = NULL;
    n = tmp;
   }
   if(!foundoldfirst){
    mRoot = NULL;
   }
   if(!foundfirst){
    result.mRoot = NULL;
   }
  }
  return result;
}

#endif
