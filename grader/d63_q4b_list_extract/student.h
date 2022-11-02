#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
    while(a != b){
        iterator tmp = a;
        a++;
        if(tmp.ptr->data == value){
            node* n = tmp.ptr;
            n->prev->next = n->next;
            n->next->prev = n->prev;

            n->next = output.mHeader->next;
            output.mHeader->next->prev = n;

            n->prev = output.mHeader;
            output.mHeader->next = n;
            mSize--;
            output.mSize++;
        }
    }
}
/*
6 -1 0 5
10 -1 30 -1 40 -1
*/

#endif
