// Your code here

int get_height(node *n, KeyT& least, int& maximbalance){
    if(n==NULL){
        return -1;
    }
    int heightleft = get_height(n->left,least,maximbalance);
    int heightright = get_height(n->right,least,maximbalance);
    int imbalance = heightleft-heightright;
    if(imbalance<0){
        imbalance = -imbalance;
    }
    if(imbalance>maximbalance){
        least = n->data.first;
        maximbalance = imbalance;
    }else if(imbalance==maximbalance){
        if(mLess(n->data.first,least)){
            least = n->data.first;
        }
    }
    if(heightleft>heightright){
        return 1+heightleft;
    }else{
        return 1+heightright;
    }
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    
    KeyT least = mRoot->data.first;
    int maximbalance = 0;
    get_height(mRoot,least,maximbalance);
    return least;
}
