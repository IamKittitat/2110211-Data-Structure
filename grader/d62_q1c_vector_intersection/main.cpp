#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<int> ans,s2;
    int n,m,ip;
    cin >> n >> m;
    vector<int> v1;
    for(int i =0;i<n;i++){
        cin >> ip;
        v1.push_back(ip);
    }
    for(int i =0;i<m;i++){
        cin >> ip;
        s2.insert(ip);
    }
    for(int i =0;i<n;i++){
        cout << "CHECK " << v1[i];
        if(s2.find(v1[i]) != s2.end()) {
            ans.insert(v1[i]);
            cout << "ans " << endl;
        }
    }
    for (auto &x :ans){
        cout << x << " ";
    }
}
