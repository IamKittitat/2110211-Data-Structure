#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
    T tmp = front();
    std::cout << "CHECK " << tmp << std::endl;
    std::cout << "CHECK2 " << mData[mFront] << std::endl;
    mData[mFront] = back();
    std::cout << "CHECK3 " << mData[mFront] << std::endl;
    std::cout << "CHECK3 " << mData[(mFront + mSize - 1) % mCap] << std::endl;
    mData[(mFront + mSize - 1) % mCap] = tmp;
    std::cout << "CHECK4 " << mData[(mFront + mSize - 1) % mCap] << std::endl;
    /*if(!empty()){
        T tmp = back();
        mFront = (mFront + mCap - 1)%mCap;
        mData[mFront] = tmp;
    }*/
}

#endif
