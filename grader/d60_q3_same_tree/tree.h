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
    bool isSameBinaryTree(Tree& t) {
        // Insert your code here
        if(mRoot == NULL && t.mRoot == NULL) return true;
        return isSameBinaryTree(mRoot,t.mRoot);
    }
    bool  isSameBinaryTree(Node* a,Node* b){
        // Preorder Travesal!
        /*if(a->data == b->data){
            bool lc=true,rc=true;
            if(a->left != NULL && b->left != NULL) lc = isSameBinaryTree(a->left,b->left);
            if(a->right != NULL && b->right != NULL) rc = isSameBinaryTree(a->right,b->right);

            if(!lc || !rc) return false;
            return true;
        }
        return false;*/
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;
        bool c1,c2,c3;
        c1 = a->data == b->data;
        c2 = isSameBinaryTree(a->left, b->left);
        c3 = isSameBinaryTree(a->right, b->right);
        return c1 && c2 && c3;
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
