#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
    stack<T> s;
    for(int i = 0;i<pos;i++){
        s.push(top());
        pop();
    }
    push(value);
    for(int i = 0;i<pos;i++){
        push(s.top());
        s.pop();
    }
}

#endif
