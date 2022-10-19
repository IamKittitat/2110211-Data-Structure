#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
    int ans = 0;
    for(int i = 0;i<mSize;i++){
        if(mLess(mData[pos],mData[i])){
            ans++;
        }
    }
    return ans;
}

#endif


// 5 4 3 2 1

