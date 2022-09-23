#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
    if(!empty()){
        T tmp = back();
        mFront = (mFront + mCap - 1)%mCap;
        mData[mFront] = tmp;
    }
}

#endif
