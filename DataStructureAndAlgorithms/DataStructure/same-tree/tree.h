#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool checker(Node *n,Node *m) {
        if (n == NULL && m == NULL) return true;
        if ((n==NULL && m!=NULL)||(n!=NULL && m==NULL)) return false;
        if(n->data != m->data){
            return false;
        }
        return ((n->data == m->data) && checker(n->left,m->left) && checker(n->right,m->right));
    }
    bool isSameBinaryTree(Tree& t) {
        if(mSize != t.mSize){
            return false;
        }
        if(mSize==0 && t.mSize == 0){
            return true;
        }
        return checker(mRoot,t.mRoot);
    }



protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
