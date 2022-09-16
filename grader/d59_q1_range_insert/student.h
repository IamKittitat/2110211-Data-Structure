#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  T *newMData = new T[mSize + (last-first)];
  int newSize = mSize + (last-first);
  int idx = 0;
  auto i = begin();
  while(i!=position){
    newMData[idx] = *i;
    idx++;
    i++;
  }

  while(first != last){
    newMData[idx] = *first;
    first++;
    idx++;
  }
  while(i != end()){
    newMData[idx] = *i;
    idx++;
    i++;
  }
  delete []mData;
  mData = newMData;
  mSize = newSize;
  mCap = newSize;
}

#endif
