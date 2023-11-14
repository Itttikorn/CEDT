void shift(int k) {
	int pos;
	if(k>=0){
		pos = k%mSize;
	}else{
		pos = (mSize-(k*(-1))%mSize)%mSize;
	}
	auto thisnode = mHeader->next;
	for(int i=0;i<pos;i++){
			thisnode = thisnode->next;
	}
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;
	thisnode->prev->next = mHeader;
	mHeader->prev = thisnode->prev;
	thisnode->prev = mHeader;
	mHeader->next = thisnode;
}
