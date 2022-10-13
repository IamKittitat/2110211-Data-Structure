#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    int a = first-begin(),b=last-begin();
    for(int i = a;i<b;i++){
        mData[i] = mData[a+(i-a+k)%(b-a)];
    }
}

#endif
