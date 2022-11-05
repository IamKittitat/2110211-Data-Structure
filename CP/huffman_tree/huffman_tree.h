#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include<iostream>
#include<queue>
#include<vector>

class huffman_tree{
    protected:
        class huffman_node{
            public:
                char letter;
                int freq;
                huffman_node *left,*right;
                huffman_node(): letter('*'),freq(0),left(NULL),right(NULL){}
                huffman_node(char letter,int freq,huffman_node* left,huffman_node* right): letter(letter),freq(freq),left(left),right(right){}

                bool is_leaf(){return left == NULL && right == NULL;}
        };
        class node_comparator{
            public:
                bool operator()(const huffman_node *a,const huffman_node *b){
                    return a->freq > b->freq;
                }
        };

        huffman_node* root;

        void build_tree(std::vector<huffman_node*> data){
            std::priority_queue<huffman_node*,std::vector<huffman_node*>,node_comparator> pq;
            for(auto &x : data) pq.push(x);
            while(pq.size() > 1){
                huffman_node* left = pq.top();pq.pop();
                huffman_node* right = pq.top();pq.pop();
                pq.push(new huffman_node('*',left->freq+right->freq,left,right));
            }
            root = pq.top();
        }

        void delete_node(huffman_node* n){
            if(n == NULL) return;
            delete_node(n->left);
            delete_node(n->right);
            delete n;
        }
    public:
        // Constructor
        huffman_tree(std::string s){
            std::map<char,int> m;
            for(char &c: s) m[c]++;
            std::vector<huffman_node*> nodes;
            for(auto &x : m) nodes.push_back(new huffman_node(x.first,x.second,NULL,NULL));
            build_tree(nodes);
        }

        // print
        void print(huffman_node *n,std::string s){
            if(n->is_leaf()) std::cout << n->letter << ": " << s << " with " << n->freq << std::endl;
            else{
                print(n->left,s+"0");
                print(n->right,s+"1");
            }
        }
        void print(){
            print(root,"");
        }

        // Destructor
        ~huffman_tree(){
            delete_node(root);
        }

};

#endif // HUFFMAN_TREE
