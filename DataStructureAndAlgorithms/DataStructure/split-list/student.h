void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int middle = (size()+1)/2;
    auto middlepos = begin();
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    for(int i=0;i<middle;i++){
        middlepos++;
    }
    middlepos.ptr->prev->next = list1.mHeader;
    list1.mHeader->prev = middlepos.ptr->prev;

    list2.mHeader->prev->next = middlepos.ptr;
    middlepos.ptr->prev = list2.mHeader->prev;
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;

    mHeader->next=mHeader;
    mHeader->prev=mHeader;
    list2.mSize+=(mSize-middle);
    mSize=0;
    list1.mSize+=middle;

}
