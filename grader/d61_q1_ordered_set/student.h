#include <vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    vector<T> sortedA = A;
    sort(sortedA.begin(),sortedA.end());
    v = A;
    for(auto &x:B){
        auto it = upper_bound(sortedA.begin(),sortedA.end(),x);
        it--;
        if(it < sortedA.end() && it >= sortedA.begin() && *it != x) v.push_back(x);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    vector<T> sortedB = B;
    sort(sortedB.begin(),sortedB.end());
    for(auto &x : A){
        auto it = upper_bound(sortedB.begin(),sortedB.end(),x);
        it--;
        if(it < sortedB.end() && it >= sortedB.begin() && *it == x)v.push_back(x);
    }
    return v;
}
