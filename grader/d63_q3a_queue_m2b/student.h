#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
    T tmp = mData[(mFront+pos)%mCap];
    for(int i = pos;i<mSize-1;i++){
        mData[(mFront+i)%mCap] = mData[(mFront+1+i)%mCap];
    }
    mData[(mFront+mSize-1)%mCap] = tmp;
}

#endif
