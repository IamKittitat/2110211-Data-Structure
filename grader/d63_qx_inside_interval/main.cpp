#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,a,b,ip;
    vector<pair<int,int>> v;
    cin >> n >> m;
    for(int i = 0; i< n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i< m ; i++){
        cin >> ip;
        auto it = upper_bound(v.begin(),v.end(),make_pair(ip,INT_MAX));
        it--;
        if(it >= v.begin() && it->first <= ip && ip <= it->second) cout << "1 ";
        else cout << "0 ";
    }
}
