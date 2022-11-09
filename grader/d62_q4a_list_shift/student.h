#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::shift_left() {
  // your code here
    node *first =  mHeader->next,*second = mHeader->next->next,*last = mHeader->prev;
    mHeader->prev->next = first;
    mHeader->next->next->prev = mHeader;
    mHeader->next->next = mHeader;
    mHeader->next->prev = last;
    mHeader->prev = first;
    mHeader->next = second;
}

#endif
