#include <vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
   set<T> s;
   vector<T> ans;
   for(int i = 0 ; i< A.size();i++){
        ans.push_back(A[i]);
        s.insert(A[i]);
   }
   for(int i = 0 ; i < B.size();i++){
        if(s.find(B[i]) == s.end()) ans.push_back(B[i]);
   }
   return ans;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    set<T> s;
    vector<T> ans;
   for(int i = 0 ; i< B.size();i++){
        s.insert(B[i]);
   }
   for(int i = 0 ; i < A.size();i++){
        if(s.find(A[i]) != s.end()) ans.push_back(A[i]);
   }
   return ans;
}
