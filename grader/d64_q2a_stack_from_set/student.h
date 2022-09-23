#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
    int n = 0 ;
    for(auto it = first;it!=last;it++) n++;
    mData = new T[n]();
    mSize = n;
    mCap = mSize;
    int idx = n-1;
    for(auto it = first;it!=last;it++,idx--){
        mData[idx] = *it;
    }
}

#endif
