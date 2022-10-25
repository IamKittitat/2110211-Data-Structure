#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
   std::map<T,size_t> m;
   std::vector<std::pair<T,size_t>> ans;
   for(int i =0 ; i<mSize;i++){
        m[mData[(mFront+i)%mCap]]++;
   }
   for(auto &x :k){
        ans.push_back({x,m[x]});
   }
   return ans;
}

#endif
