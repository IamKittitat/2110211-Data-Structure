#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
    if(empty() && other.size()>0) return true;
    for(int i = 0 ; i < size();i++){
        if(i>=other.size()) return false;
        if(mData[i] < other[i]) return true;
        if(mData[i] > other[i]) return false;
    }
    if(size() < other.size()) return true;
    return false;
}

#endif
