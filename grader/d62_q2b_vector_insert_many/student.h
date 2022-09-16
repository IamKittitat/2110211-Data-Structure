#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<bits/stdc++.h>
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  sort(data.begin(),data.end());
  T *newMData = new T[size()+data.size()];
  int idx = 0,idx2=0;
  for(size_t i = 0 ;i<=mSize;i++){
    if((size_t)data[idx].first == i){
        newMData[idx2] = data[idx].second;
        idx++;
        idx2++;
    }
    if(i<mSize){
       newMData[idx2] = mData[i];
        idx2++;
    }
  }
  delete [] mData;
  mData = newMData;
  mSize = size()+data.size();
  mCap = mSize;
}

#endif
