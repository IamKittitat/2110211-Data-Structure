#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
    for(CP::list<T> &l : ls){
        mSize+=l.size();
        mHeader->prev->next = l.mHeader->next; //pink
        l.mHeader->next->prev = mHeader->prev; //red
        mHeader->prev = l.mHeader->prev; //yellow
        l.mHeader->prev->next = mHeader; //brown

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

