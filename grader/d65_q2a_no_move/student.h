#ifndef __STUDENT_H_
#define __STUDENT_H_
using namespace std;
#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
    int ridx = idx+1;
    int sval,fval;
    auto fidx = lower_bound(aux.begin(),aux.end(),ridx);
    fval = fidx - aux.begin();
    auto sidx = fidx;
    sidx--;
    if(sidx < aux.begin()) sval = 0;
    else sval = *sidx;
    return mData[fval][idx-sval];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
    int ls = aux.size() > 0 ? aux[aux.size()-1] : 0;
    aux.push_back(ls +mData.back().size());
}

#endif


/*
4 2
1 99
2 5
1 97
*/
