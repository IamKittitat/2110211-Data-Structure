#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  int f = 0,l = 1;
  for(int i = 0;i<k;i++) f = 2*f + 1;
  l = f*2 + 1;
  l -= 1;
  l = mSize < l ? mSize-1 : l;
  for(int i = f;i<=l;i++) r.push_back(mData[i]);
  std::sort(r.rbegin(),r.rend(),mLess);
  return r;
}

#endif

