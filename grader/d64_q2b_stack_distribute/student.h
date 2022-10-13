#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
    std::vector<std::vector<T>> v(k);
    int si = 0,idx=0,k2=0;
    for(int i = 0;i<k;i++){
        si = (mSize-idx)/(k-k2);
        if((mSize-idx)%(k-k2) != 0) si++;
        for(int j=0;j<si;j++){
            v[i].push_back(mData[mSize-1-idx]);
            idx++;
        }
        k2++;
    }
    return v;
}
#endif
