#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<bits/stdc++.h>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
    sort(data.begin(),data.end());
    T *arr = new T[mSize+data.size()];
    int idx = 0,pos=0;
    for(int i = 0 ; i < mSize;i++){
        if(i == data[pos].first) arr[idx++] = data[pos++].second;
        arr[idx++] = mData[i];
    }
    if(mSize == data[pos].first) arr[idx++] = data[pos++].second;
    delete [] mData;
    mData = arr;
    mSize = mSize+data.size();
    mCap = mSize;
}

#endif
