#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    T *newMData = new T[mCap]();
    newMData[0] = mData[(mFront+pos)%mCap];
    int idx = 1;
    for(int i = 0;i<mSize;i++){
        if(i != pos){
            newMData[idx++] = mData[(mFront+i)%mCap];
        }
    }
    delete [] mData;
    mData = newMData;
    mFront = 0;
}

#endif
