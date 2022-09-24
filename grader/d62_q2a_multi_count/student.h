#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T,size_t> mmm;
    for(int i = 0; i < mSize;i++){
        T key = mData[(mFront+i)%mCap];
        mmm[key]++;
    }
    std::vector<std::pair<T,size_t>> ans;
    for(auto &x : k){
        ans.push_back({x,mmm[x]});
    }
    return ans;
}

#endif
