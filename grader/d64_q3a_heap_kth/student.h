#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include "priority_queue.h"
using namespace std;

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
    //write your code here
    //can include anything
    vector<T> tmp;
    for(int i = 0 ;i < mSize;i++) tmp.push_back(mData[i]);
    sort(tmp.begin(),tmp.end(),mLess);
    return tmp[tmp.size()-k];
}

#endif
