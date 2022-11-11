void replace(const T& x, list<T>& y) {
  //write your code here
    auto it = begin();
    while(it != end()){
        if(*it == x){
            list<T> y_tmp = y;
            node *tmp = it.ptr,*first = y_tmp.mHeader->next,*last = y_tmp.mHeader->prev;
            it++;

            if(!y.empty()){
                tmp->prev->next = first;
                tmp->next->prev = last;
                first->prev = tmp->prev;
                last->next = tmp->next;
                delete tmp;

                y_tmp.mHeader->next = y_tmp.mHeader;
                y_tmp.mHeader->prev = y_tmp.mHeader;
                y_tmp.mSize = 0;
            } else{
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
            }
            mSize = mSize + y.size() - 1;
        }else{
            it++;
        }
    }
}
