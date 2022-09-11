#include "pair.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool firstDigit(const CP::pair<int,string> p){
    return (p.first == 1);
}

int main(){
    CP::pair<int,string> p1 = {1,"one"};
    CP::pair<int,string> p2 = {1,"one"};
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    cout << (p1 < p2) <<endl;
    cout << (p1 != p2) <<endl;
    cout << (p1 == p2) <<endl;
    cout << (p1 >= p2) <<endl;

    set<CP::pair<int,string>> s1;
    s1.insert(p1);
    s1.insert(p2);
    cout << s1.begin()->first << " " << s1.begin()->second << endl;
    cout << firstDigit(p1) << " " << firstDigit(p2) << endl;

    vector<CP::pair<int,string>> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    sort(v1.begin(),v1.end());
    cout << v1[0].first << " " << v1[1].first;
}
