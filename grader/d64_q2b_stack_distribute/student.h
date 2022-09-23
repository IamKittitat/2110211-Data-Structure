#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
    std::vector<std::vector<T>> ans;
    int idx = size()-1;
    int si;
    while(idx >= 0){
        if((idx+1)%k != 0){
            si = (idx+1)/k + 1;
        } else{
            si = (idx+1)/k;
        }
        k--;
        std::vector<T> subans;
        for(int i = 0 ; i < si ; i++){
            subans.push_back(mData[idx]);
            idx--;
        }
        ans.push_back(subans);
    }
    return ans;
}
#endif
