#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
    CP::stack<T> tmp_this;
    CP::stack<T> tmp_s;
    while(!empty() && k--){
        tmp_this.push(top());
        pop();
    }
    while(!s2.empty() && m--){
        tmp_s.push(s2.top());
        s2.pop();
    }
    while(!tmp_s.empty()){
        push(tmp_s.top());
        tmp_s.pop();
    }
    while(!tmp_this.empty()){
        push(tmp_this.top());
        tmp_this.pop();
    }
}
#endif
