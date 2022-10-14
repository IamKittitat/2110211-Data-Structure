#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    stack<T> s;
    for(int i = 0;i<=b;i++){
        s.push(top());
        pop();
    }
    for(int i = a;i<=b;i++){
        push(s.top());
        push(s.top());
        s.pop();
    }
    while(!s.empty()){
        push(s.top());
        s.pop();
    }
}

#endif
