#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    T *newMData = new T[mSize];
    int idx=0;
    for(int i=0;i<mSize;i++){
        newMData[idx++] = mData[i];
    }
    delete [] mData;
    mData = newMData;
    mCap = mSize;
}

#endif
