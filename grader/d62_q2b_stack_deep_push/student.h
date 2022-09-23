#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
    CP::stack<T> s;
    for(size_t i = 0 ; i < pos ;i ++){
        if(!empty()){
            s.push(top());
            pop();
        }
    }
    push(value);
    while(!s.empty()){
        push(s.top());
        s.pop();
    }
}

#endif
