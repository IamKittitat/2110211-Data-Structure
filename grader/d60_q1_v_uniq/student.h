#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
    std::set<T> s;
    for(int i = 0 ; i < mSize;i++) s.insert(mData[i]);
    T *newMData = new T[s.size()];
    int idx=0;
    int newSize = s.size();
    for(int i =0 ;i<mSize;i++){
        if(s.find(mData[i]) != s.end()){
            newMData[idx] = mData[i];
            s.erase(mData[i]);
            idx++;
        }
    }
    delete [] mData;
    mData = newMData;
    mSize = newSize;
    mCap = mSize;
}

#endif
