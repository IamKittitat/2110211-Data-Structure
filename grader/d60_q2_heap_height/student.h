#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
    int i =-1, s = mSize,tmp=1;
    while(s > 0){
        s -= tmp;
        tmp *= 2;
        i++;
    }
    return i;
}

#endif

