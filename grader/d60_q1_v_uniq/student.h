#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
    std::set<T> s;
    T *arr = new T[mSize];
    int idx=0;
    for(int i =0;i<mSize;i++){
        if(s.find(mData[i]) == s.end()) arr[idx++] = mData[i];
        s.insert(mData[i]);
    }
    delete [] mData;
    mData = arr;
    mSize = idx;
    mCap = mSize;
}

#endif
