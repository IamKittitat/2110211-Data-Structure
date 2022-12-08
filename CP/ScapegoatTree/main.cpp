#include <iostream>
#include "ScapegoatTree.h"
using namespace std;

int main() {
    CP::map_sgt<float,int> sgt;
    sgt.insert({7,0});
    sgt.insert({6,0});
    sgt.insert({8,0});
    sgt.insert({5,0});
    sgt.insert({9,0});
    sgt.insert({2,0});
    sgt.insert({1,0});
    sgt.insert({4,0});
    sgt.insert({0,0});
    sgt.insert({3,0});
    sgt.insert({3.5,0});

    cout << "Preorder traversal of the ScapeGoat tree\n";
    sgt.preorder();
    cout << "Postorder traversal of the ScapeGoat tree\n";
    sgt.postorder();
    cout << "Inorder traversal of the ScapeGoat tree\n";
    sgt.inorder();

    sgt.erase(3); sgt.erase(3.5); sgt.erase(7); sgt.erase(9);

    cout << "Preorder traversal of the ScapeGoat tree\n";
    sgt.preorder();
    cout << "Postorder traversal of the ScapeGoat tree\n";
    sgt.postorder();
    cout << "Inorder traversal of the ScapeGoat tree\n";
    sgt.inorder();
}
