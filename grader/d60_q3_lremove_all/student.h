#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
    auto it = begin();
    while(it != end()){
        if(*it == value){
            node *tmp = it.ptr;
            it++;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            mSize--;
        } else{
            it++;
        }
    }
}

#endif
