#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  if(ptr == NULL) return 0;
  int count = process(ptr->left) + process(ptr->right);
  if((ptr->left == NULL && ptr->right!=NULL)||(ptr->left!=NULL && ptr->right==NULL)){
    count++;
  }
  return count;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  int count = process(mRoot);
  return count;
}

#endif
