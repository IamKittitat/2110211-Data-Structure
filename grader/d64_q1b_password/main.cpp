#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,l,tmp;
    string ip;
    set<string> db;
    vector<int> k;
    cin >> n >> m >> l;
    for(int i = 0; i < l;i++){
        cin >> tmp;
        k.push_back(tmp);
    }
    for(int i = 0; i < n;i++){
        cin >> ip;
        db.insert(ip);
    }
    for(int i = 0; i < m;i++){
        cin >> ip;
        string np;
        for(int j = 0 ; j<ip.size();j++){
            np += (ip[j] - 97 + k[j])%26 + 97;
        }
        if(db.count(np) != 0) cout << "Match\n";
        else cout << "Unknown\n";
    }
}
