void shift(int k) {
	// TODO: Add your code here
	if(mSize <= 1) return;
	while(k<0) k += mSize;
	k = k%mSize;
	if(k == 0) return;
	auto it = begin();
	for(int i =0;i<k;i++) it++;
	node *tmp = it.ptr, *btmp = it.ptr->prev, *first = mHeader->next, *last = mHeader->prev;
	mHeader->next = tmp;
	mHeader->prev = btmp;
	tmp->prev = mHeader;
	btmp->next = mHeader;
	first->prev = last;
	last->next = first;
}
