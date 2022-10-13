#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
    if(m>0 && mData <= a && a < mData+mSize && mData <= b && b < mData+mSize && mData <= a+m-1 && a+m-1 < mData+mSize && mData <= b+m-1 && b+m-1 < mData+mSize && ((a<b && a+m-1<b) || (b<a && b+m-1<a))){
        vector<T> v;
        for(int i = 0;i<m;i++){
            v.push_back(*(b+i));
            *(b+i) = *(a+i);
        }
        for(int i = 0 ; i<m;i++){
            *(a+i) = v[i];
        }
        return true;
    }
    return false;
}

#endif
