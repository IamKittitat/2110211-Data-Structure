#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something
    std::vector<std::vector<T>> v(k),ans(k);
    int idx = 0;
    for(int i = mSize-1;i>=0;i--,idx++){
        v[idx%k].push_back(mData[i]);
    }
    idx = 0 ;
    for(auto &x : v){
        for(int i = x.size()-1;i>=0;i--) ans[idx].push_back(x[i]);
        idx++;
    }
    return ans;
}

#endif

