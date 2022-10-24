#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <cmath>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
    /*if(mSize == 0) return -1;
    int s = mSize-1,count = 0;
    while(s > 0){
        s = (s-1)/2;
        count++;
    }
    return count;*/
    if(mSize == 0) return -1;
    return log(mSize)/log(2);
}

#endif

