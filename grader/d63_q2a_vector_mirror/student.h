#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror()
{
    //write your code here
    ensureCapacity(2*mSize);
    for(int i = 0; i< mSize; i++)
    {
        *(mData+mSize+i) = *(mData+mSize-i-1);
    }
    this->mSize = 2*mSize;
}

#endif
