void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    size_t ns = mSize;
    for(int i = 0;i<(mSize+1)/2;i++){
        node *tmp = mHeader->next,*last1 = list1.mHeader->prev;
        mHeader->next = mHeader->next->next;
        list1.mHeader->prev->next = tmp;
        list1.mHeader->prev = tmp;
        tmp->next = list1.mHeader;
        tmp->prev = last1;
        ns--;
        list1.mSize++;
    }
    mSize = ns;
    for(int i = 0;i<mSize;i++){
        node *tmp = mHeader->next,*last2 = list2.mHeader->prev;
        mHeader->next = mHeader->next->next;
        list2.mHeader->prev->next = tmp;
        list2.mHeader->prev = tmp;
        tmp->next = list2.mHeader;
        tmp->prev = last2;
        list2.mSize++;
    }
    mSize = 0;
}
