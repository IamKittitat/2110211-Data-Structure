#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
    for(CP::list<T> &l : ls){
        if(l.empty()) continue;
        node *hd1 = mHeader,*l1 = mHeader->prev,*hd2 = l.mHeader,*f2 = l.mHeader->next,*l2 = l.mHeader->prev;
        mSize += l.size();

        hd1->prev = l2;
        l1->next = f2;
        f2->prev = l1;
        l2->next = hd1;

        l.mHeader->next = l.mHeader;
        l.mHeader->prev = l.mHeader;
        l.mSize = 0;
    }
}

#endif
/*
3 4
1 2 3
3 10 20 30
1 100
0
3 990 991 992
*/
