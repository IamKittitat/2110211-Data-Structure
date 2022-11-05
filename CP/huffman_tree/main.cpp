#include <bits/stdc++.h>
#include "huffman_tree.h"

using namespace std;

void print_range1(int step,int goal){
    if(step < goal){
        cout << step << " ";
        print_range1(step+1,goal);
    }
}

void print_range2(int step,int goal){
    if(step < goal){
        print_range2(step+1,goal);
        cout << step << " ";
    }
}

int main(){
    huffman_tree hf("nevergonnagiveyouupnevergonnaletyoudownnevergonnarunaroundanddesertyou");
    hf.print();
}

/*
nevergonnagiveyouupnevergonnaletyoudownnevergonnarunaroundanddesertyou
*/
