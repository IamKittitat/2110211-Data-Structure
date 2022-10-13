#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  T *arr = new T[mSize+last-first];
  int idx=0;
  for(int i = 0 ; i < position-begin();i++) arr[idx++] = mData[i];
  while(first != last){
    arr[idx++] = *first;
    first++;
  }
  for(int i = position-begin(); i < mSize;i++) arr[idx++] = mData[i];

  delete []mData;
  mData = arr;
  mSize = idx;
  mCap = mSize;
}

#endif
