#ifndef CP_MAP_BST
#define CP_MAP_BST

namespace CP{
    template<typename KeyT,typename MappedT,typename CompareT = std::less<KeyT>>
    class map_bst{
        protected:
            typedef std::pair<KeyT,MappedT> ValueT;
            class node{
                friend class map_bst;
                public:
                    ValueT data;
                    node *left,*right,*parent;

                    node():data(ValueT()),left(NULL),right(NULL),parent(NULL){}
                    node(const ValueT& data,node *left,node *right,node *parent):data(data),left(left),right(right),parent(parent){}
            };
            class tree_iterator{
                protected:
                    node* ptr;
                public:
                    tree_iterator():ptr(NULL){}
                    tree_iterator(node* a):ptr(a){}

                    tree_iterator& operator++(){
                        if(ptr->right == NULL){
                            node *parent = ptr->parent;
                            while(parent != NULL && parent->right == ptr){
                                ptr = parent;
                                parent = ptr->parent;
                            }
                            ptr = parent;
                        } else{
                            ptr = ptr->right;
                            while(ptr->left != NULL) ptr = ptr->left;
                        }
                        return *this;
                    }
                    tree_iterator& operator--(){
                        if(ptr->left == NULL){
                            node *parent = ptr->parent;
                            while(parent != NULL && parent->left == ptr){
                                ptr = parent;
                                parent = ptr->parent;
                            }
                            ptr = parent;
                        } else{
                            ptr = ptr->left;
                            while(ptr->right != NULL) ptr = ptr->right;
                        }
                        return *this;
                    }
                    tree_iterator& operator++(int){
                        tree_iterator tmp(*this);
                        operator++();
                        return tmp;
                    }
                    tree_iterator& operator--(int){
                        tree_iterator tmp(*this);
                        operator--();
                        return tmp;
                    }

                    ValueT& operator*(){return ptr->data;}
                    ValueT* operator->(){return &(ptr->data);}
                    bool operator==(const tree_iterator& other){return ptr == other.ptr;}
                    bool operator!=(const tree_iterator& other){return ptr != other.ptr;}
            };
        public:
            typedef tree_iterator iterator;
        protected:
            node *mRoot;
            size_t mSize;
            CompareT mLess;

            int compare(const KeyT& k1, const KeyT& k2){
                if(mLess(k1,k2)) return -1;
                if(mLess(k2,k1)) return 1;
                return 0;
            }

            node* find_node(const KeyT& k,node* r, node* &parent){
                while(r != NULL){
                    int cmp = compare(k,r->data.first);
                    if(cmp == 0) return r;
                    parent = r;
                    r = cmp < 0 ? r->left : r->right;

                }
                return NULL;
            }

            node*& child_link(node* parent,KeyT key){
                if(parent == NULL) return mRoot;
                return mLess(key,parent->data.first) ? parent->left: parent->right ;
            }

            node* find_min_node(node *n){
                if(n->left == NULL) return n;
                return find_min_node(n->left);
            }


            node* copy(node* n,node* parent){
                if(n == NULL) return NULL;
                node *tmp = new node();
                tmp->data = n->data;
                tmp->left = copy(n->left,tmp);
                tmp->right = copy(n->right,tmp);
                tmp->parent = parent;
                return tmp;
            }

            void delete_all_nodes(node * n){
                if (n == NULL) return;
                delete_all_nodes(n->left);
                delete_all_nodes(n->right);
                delete n;
            }


        public:
            //-------------- constructor & copy operator ----------

            // default constructor
            map_bst(const CompareT& c = CompareT()): mRoot(NULL),mSize(0),mLess(c){}

            // copy constructor
            map_bst(map_bst<KeyT,MappedT,CompareT>& a){
                mRoot = copy(a.mRoot,NULL);
                mSize = a.mSize;
                mLess = a.mLess;
            }

            // copy assignment operator using copy-and-swap idiom
            map_bst<KeyT,MappedT,CompareT>& operator=(map_bst<KeyT,MappedT,CompareT> other)  {
                using std::swap;
                swap(this->mRoot, other.mRoot);
                swap(this->mLess, other.mLess);
                swap(this->mSize, other.mSize);
                return *this;
            }

            ~map_bst(){
                clear();
            }

            //------------- capacity function -------------------
            bool empty() {
                return mSize == 0;
            }

            size_t size() {
                return mSize;
            }

            //----------------- iterator ---------------
            iterator begin(){
                return iterator(mRoot == NULL ? NULL : find_min_node(mRoot));
            }
            iterator end(){
                return iterator(NULL);
            }

            //----------------- modifier -------------
            void clear(){
                delete_all_nodes(mRoot);
                mRoot = NULL;
                mSize = 0;
            }

            MappedT& operator[](const KeyT& key){
                node *parent = NULL;
                node *n = find_node(key,mRoot,parent);
                if(n == NULL){
                    n = new node({key,MappedT()},NULL,NULL,parent);
                    child_link(parent,key) = n;
                    mSize++;
                }
                return n->data.second;
            }

            std::pair<iterator,bool> insert(const ValueT& val){
                node *parent = NULL;
                node *n = find_node(val.first,mRoot,parent);
                bool not_found = (n == NULL);
                if(not_found){
                    n = new node(val,NULL,NULL,parent);
                    child_link(parent,val.first) = n;
                    mSize++;
                }
                return {iterator(n),not_found};
            }

            iterator find(const KeyT &key){
                node *parent = NULL;
                node *n = find_node(key,mRoot,parent);
                return n == NULL ? end() : iterator(n);
            }

            size_t erase(const KeyT &key){
                if(mRoot == NULL) return 0;

                node *parent = NULL;
                node *n = find_node(key,mRoot,parent);
                if(n == NULL) return 0;
                if(n->left != NULL && n->right != NULL){
                    node *min = find_min_node(n->right);
                    node * &link = child_link(min->parent, min->data.first);
                    link = (min->left == NULL) ? min->right : min->left;
                    if (link != NULL) link->parent = min->parent;
                    std::swap(n->data.first, min->data.first);
                    std::swap(n->data.second, min->data.second);
                    n = min; // we are going to delete this node instead
                } else{
                    node * &link = child_link(n->parent, key);
                    link = (n->left == NULL) ? n->right : n->left;
                    if (link != NULL) link->parent = n->parent;
                }
                delete n;
                mSize--;
                return 1;
                return 1;
            }


            void print_node(node *n,size_t depth) {
                if (n != NULL) {
                    if (n->right != NULL && n->right->parent != n)
                      std::cout << "parent of " << n->right->data.first << std::endl;
                    if (n->left != NULL && n->left->parent != n)
                      std::cout << "parent of " << n->left->data.first << std::endl;
                    print_node(n->right,depth+1);
                    for (size_t i = 0;i < depth;i++) std::cout << "--";
                    std::cout << " " << n->data.first << ":" << n->data.second << std::endl;
                    print_node(n->left,depth+1);
                }
            }

            void print() {
                std::cout << " ======== size = " << mSize << " ========= " << std::endl;
                print_node(mRoot,0);
            }
            bool checkParent() {
                return checkParent(mRoot);
            }
            bool checkParent(node *r) {
                if (r == NULL) return true;
                if (r->left != NULL && r != r->left->parent) return false;
                if (r->right != NULL && r != r->right->parent) return false;
                if (!checkParent(r->left)) return false;
                return checkParent(r->right);
            }
            bool checkInorder() {
                return checkInorder(mRoot);
            }
            bool checkInorder(node *r) {
                if (r==NULL) return true;
                if (r->left != NULL && !mLess(r->left->data.first,r->data.first)) return false;
                if (r->right != NULL && !mLess(r->data.first, r->right->data.first)) return false;
                if (!checkInorder(r->left)) return false;
                return checkInorder(r->right);
            }

    };
}
#endif // CP_MAP_BST
