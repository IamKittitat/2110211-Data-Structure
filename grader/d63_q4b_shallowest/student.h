#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
    if(n == NULL) return -1;
    int left = shallowest_leaf(n->left);
    int right = shallowest_leaf(n->right);
    if(left == -1 || right == -1) return 1+std::max(left,right);
    else return 1+std::min(left,right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
    return shallowest_leaf(mRoot);
}


#endif
