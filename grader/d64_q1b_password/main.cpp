#include <bits/stdc++.h>

using namespace std;

set<string> db;
vector<int> key;
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,l,tmp;
    string pass,ip;
    cin >> n >> m >> l;
    for(int i = 0 ; i < l ; i++){
        cin >> tmp;
        key.push_back(tmp);
    }
    for(int i = 0 ; i < n; i++){
        cin >> pass;
        db.insert(pass);
    }
    for(int i = 0 ; i < m; i++){
        string cip;
        cin >> ip;
        for(int j = 0;j<ip.length();j++){
            cip += ((ip[j] + key[j])-97)%26 + 97;
        }
        if(db.find(cip) != db.end()) cout << "Match\n";
        else cout << "Unknown\n";
    }
}
