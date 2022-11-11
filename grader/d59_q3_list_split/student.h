#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
    CP::list<T> result;
    if(it == end()) return result;

    mSize = pos;
    result.mSize = mSize-pos;

    node *lt = it.ptr->prev, *first = it.ptr, *last = mHeader->prev;
    lt->next = mHeader;
    mHeader->prev = lt;
    result.mHeader->next = first;
    result.mHeader->prev = last;
    first->prev = result.mHeader;
    last->next = result.mHeader;
    return result;
}

#endif
