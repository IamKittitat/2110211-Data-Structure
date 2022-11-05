#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
    auto it = a;
    while(a!=b){
        b--;
        if(a == b) break;
        std::cout <<"CHECK : " <<  a.ptr->data << " " << b.ptr->data;
        std::swap(a.ptr->data,b.ptr->data);
        a++;
    }
    return it;
}

#endif
/*
u 1
u 2
u 3
u 4
r 1 2
p
q
*/
