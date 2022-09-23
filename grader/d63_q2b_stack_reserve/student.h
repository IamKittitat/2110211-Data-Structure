#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int res1 = mCap-mSize;
    int res2 = other.mCap - other.mSize;
    if(res1 < res2) return -1;
    if(res1 == res2) return 0;
    if(res1 > res2) return 1;
}

#endif
