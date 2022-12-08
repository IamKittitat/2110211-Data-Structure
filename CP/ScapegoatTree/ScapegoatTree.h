#ifndef CP_MAP_SGT
#define CP_MAP_SGT

#include<vector>
#include<cmath>

namespace CP{
    template<typename KeyT,typename MappedT,typename CompareT = std::less<KeyT>>
    class map_sgt{
        protected:
            typedef std::pair<KeyT,MappedT> ValueT;
            class node{
                friend class map_sgt;
                public:
                    ValueT data;
                    node *left,*right,*parent;

                    node():data(ValueT()),left(NULL),right(NULL),parent(NULL){}
                    node(const ValueT& data,node *left,node *right,node *parent):data(data),left(left),right(right),parent(parent){}
            };
            node *mRoot;
            size_t mSize;
            size_t mMaxNode;
            float mAlpha;
            CompareT mLess;

            int compare(const KeyT& k1, const KeyT& k2){
                if(mLess(k1,k2)) return -1;
                if(mLess(k2,k1)) return 1;
                return 0;
            }

            std::pair<node*,int> find_node(const KeyT& k,node* r, node* &parent){
                int depth = 0;
                while(r != NULL){
                    int cmp = compare(k,r->data.first);
                    if(cmp == 0) return {r,depth};
                    parent = r;
                    r = cmp < 0 ? r->left : r->right;
                    depth++;
                }
                return {NULL,depth};
            }

            node*& child_link(node* parent,KeyT key){
                if(parent == NULL) return mRoot;
                return mLess(key,parent->data.first) ? parent->left: parent->right ;
            }

            node* find_min_node(node *n){
                if(n->left == NULL) return n;
                return find_min_node(n->left);
            }

            void delete_all_nodes(node * n){
                if (n == NULL) return;
                delete_all_nodes(n->left);
                delete_all_nodes(n->right);
                delete n;
            }

            float nodeSize(node *n)
            {
                if (n == NULL) return 0;
                return 1 + nodeSize(n->left) + nodeSize(n->right);
            }

            void rebuildTree(node *n){
                std::vector<node*> nodes;
                storeNodes(n,nodes);
                node *parent = n->parent == NULL ? NULL : n->parent;

                // Constructs BST from nodes[]
                int amount = nodes.size();
                node *new_subtree_root = genTree(parent,nodes,0,amount-1);
                child_link(parent,new_subtree_root->data.first) = new_subtree_root;
                mMaxNode = mSize;
            }

            void storeNodes(node *n,std::vector<node*> &nodes)
            {
                if(n==NULL) return;

                storeNodes(n->left, nodes);
                nodes.push_back(n);
                storeNodes(n->right, nodes);
            }

            node* genTree(node *parent,std::vector<node*> nodes,int l,int r){
                if (l > r) return NULL;
                int mid = (l+r) / 2;

                node *n = nodes[mid];
                if(parent != NULL) n->parent = parent;
                n->left  = genTree(n,nodes, l, mid-1);
                n->right = genTree(n,nodes, mid+1, r);
                return n;
            }
        public:
            //-------------- constructor & copy operator ----------

            // default constructor
            map_sgt(const CompareT& c = CompareT()): mRoot(NULL),mSize(0),mMaxNode(0),mLess(c),mAlpha((float)2/(float)3){}

            // copy constructor
            map_sgt(map_sgt<KeyT,MappedT,CompareT>& a){
                mRoot = copy(a.mRoot,NULL);
                mSize = a.mSize;
                mMaxNode = a.mMaxNode;
                mLess = a.mLess;
                mAlpha = a.mAlpha;
            }

            // copy assignment operator using copy-and-swap idiom
            map_sgt<KeyT,MappedT,CompareT>& operator=(map_sgt<KeyT,MappedT,CompareT> other)  {
                using std::swap;
                swap(this->mRoot, other.mRoot);
                swap(this->mSize, other.mSize);
                swap(this->mMaxNode, other.mMaxNode);
                swap(this->mLess, other.mLess);
                swap(this->mAlpha, other.mAlpha);
                return *this;
            }

            ~map_sgt(){
                clear();
            }

            //------------- capacity function -------------------
            bool empty() {
                return mSize == 0;
            }

            size_t size() {
                return mSize;
            }

            //----------------- modifier -------------
            void clear(){
                delete_all_nodes(mRoot);
                mRoot = NULL;
                mSize = 0;
            }

            /*MappedT& operator[](const KeyT& key){
                node *parent = NULL;
                node *n = find_node(key,mRoot,parent);
                if(n == NULL){
                    n = new node({key,MappedT()},NULL,NULL,parent);
                    child_link(parent,key) = n;
                    mSize++;
                }
                return n->data.second;
            }*/

            bool insert(const ValueT& val){
                node *parent = NULL;
                std::pair<node*,int> n_d;
                n_d = find_node(val.first,mRoot,parent);
                node *n = n_d.first;
                int depth = n_d.second;
                bool not_found = (n == NULL);
                if(not_found){
                    std::cout << "Insert " << val.first << std::endl;
                    n = new node(val,NULL,NULL,parent);
                    child_link(parent,val.first) = n;
                    mSize++;
                    mMaxNode = std::max(mSize,mMaxNode);
                    if(depth > std::floor(log(mSize)/log((float)1/(float)mAlpha))){
                        std::cout << "REBALANCE FROM INSERT\n";
                        node *p = n->parent;
                        while (nodeSize(p) <= mAlpha*nodeSize(p->parent)) p = p->parent;
                        rebuildTree(p->parent);
                    }
                    return 1;
                }
                return not_found;
            }

            size_t erase(const KeyT &key){
                if(mRoot == NULL) return 0;

                node *parent = NULL;
                std::pair<node*,int> n_d;
                n_d = find_node(key,mRoot,parent);
                node *n = n_d.first;
                if(n == NULL) return 0;
                std::cout << "Erase " << key << std::endl;
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
                if(mSize <= mAlpha*mMaxNode){
                    std::cout << "REBALANCE FROM DELETE\n";
                    rebuildTree(mRoot);
                }
                return 1;
            }

            void preorder(){
                preorder(mRoot);
                std::cout << "\n";
            }
            void inorder(){
                inorder(mRoot);
                std::cout << "\n";
            }
            void postorder(){
                postorder(mRoot);
                std::cout << "\n";
            }

            void preorder(node *n){
                if(n == NULL) return;
                std::cout << n -> data.first << " ";
                preorder(n -> left);
                preorder(n -> right);
            }
            void inorder(node *n){
                if(n == NULL) return;
                inorder(n -> left);
                std::cout << n -> data.first << " ";
                inorder(n -> right);
            }
            void postorder(node *n){
                if(n == NULL) return;
                postorder(n -> left);
                postorder(n -> right);
                std::cout << n -> data.first << " ";
            }

    };
}
#endif // CP_MAP_SGT

