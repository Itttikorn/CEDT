package Exercise01;

import java.util.ArrayList;

public class StorageBox {

    private int mSize = 0;
    private int mCap = 0;
    private ArrayList mData;

    public StorageBox(){
        this.mSize = 0;
        this.mCap = 0;
        this.mData = new ArrayList();
    }

    public StorageBox(int size){
        this.mSize = 0;
        this.mCap = 0;
        this.mData = new ArrayList();
    }

    public boolean isEmpty(){
        return mSize == 0;
    }
    public boolean isFull(){
        return mSize == mCap;
    }
    public void push(Object x){
        if(isFull()){
            expand();
        }
        mData.add(x);
        mSize++;
    }

    private void expand(){
        this.mSize *= 2;
    }

    public Object pop(){
        if(isEmpty()){
            return null;
        }
        Object ret = mData.get(mSize - 1);
        mData.remove(mSize-1);
        mSize--;
        return ret;
    }

    public Object top(){
        if(isEmpty()){
            return null;
        }
        return mData.get(mSize - 1);
    }
}
