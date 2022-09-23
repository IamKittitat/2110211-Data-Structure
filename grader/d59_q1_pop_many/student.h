#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
    while(!empty() && K--) pop();
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
    std::stack<T> tmp1;
    while(!empty() && K--){
        tmp1.push(top());
        pop();
    }
    std::stack<T> ans;
    while(!tmp1.empty()){
        ans.push(tmp1.top());
        tmp1.pop();
    }
    return ans;
}

#endif
