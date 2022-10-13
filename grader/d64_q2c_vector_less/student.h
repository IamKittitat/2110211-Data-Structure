#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
    if(empty() || other.empty()) return size() < other.size();
    int idx1=0,idx2=0;
    while(idx1 < size() && idx2 < other.size()){
        if(mData[idx1] != other[idx2]) return mData[idx1] < other[idx2];
        idx1++;
        idx2++;
    }
    return size() < other.size();
}

#endif
