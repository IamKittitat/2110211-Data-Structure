#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
    /*if(k == 0) return;
    size_t a = first - begin();
    size_t b = last - begin();
    for(size_t i = a ; i < b;i++){
        int tmp;
        if(i+k >=b) tmp = (i+k)%b + a;
        else tmp = i+k;
        mData[i] = tmp;
    }*/
    if(k == 0) return;
    CP::vector<T> v_tmp(last-first);
    int idxx = 0;
    for(auto it = first;it!= last;it++,idxx++){
        v_tmp[idxx] = *it;
    }
    int idx,tmp;
    for(auto it = first;it!= last;it++){
        tmp = it-first+k;
        if(tmp >=last-first) tmp = tmp+first-last;
        *it = v_tmp[tmp];
    }

}

#endif
