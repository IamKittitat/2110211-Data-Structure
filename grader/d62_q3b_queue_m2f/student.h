#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    T *arr = new T[mSize]();
    int idx = 0;
    arr[idx++] = mData[(mFront+pos)%mCap];
    for(int i = 0;i<mSize;i++){
        if(i != pos){
            arr[idx++] = mData[(mFront+i)%mCap];
        }
    }
    delete []mData;
    mData = arr;
    mCap  = mSize;
    mFront = 0;
}

#endif
