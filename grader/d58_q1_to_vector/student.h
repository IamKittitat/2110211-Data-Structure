#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;
    int n = size();
    int idx=0;
    while(n-- && k--){
        res.push_back(mData[(mFront+idx)%mCap]);
        idx++;
    }
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
    size_t n = to-from;
    mData = new T[n]();
    mSize = n;
    mCap = n;
    mFront = 0;
    auto it = from;
    int idx=0;
    while(it != to){
        mData[idx++] = *it;
        it++;
    }
}

#endif
