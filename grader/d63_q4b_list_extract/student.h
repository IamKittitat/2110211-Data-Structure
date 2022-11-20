#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
    while(a!=b){
        if(a.ptr->data == value){
            node *tmp = a.ptr,*f2 = output.mHeader->next;
            a++;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;

            tmp->prev = output.mHeader;
            tmp->next = f2;

            output.mHeader->next = tmp;
            f2->prev = tmp;
            output.mSize++;
            mSize--;
        } else{
            a++;
        }
    }
}
/*
6 -1 0 5
10 -1 30 -1 40 -1
*/

#endif
