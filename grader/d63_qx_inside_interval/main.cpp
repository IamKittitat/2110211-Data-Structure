#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    pair<int,int> p;
    for(int i = 0 ; i< n ; i++)
    {
        int ip1,ip2;
        cin >> ip1 >> ip2;
        p = {ip1,ip2};
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i< m ; i++)
    {
       int q;
       cin >> q;
       p = {q,1000000000};
       auto it = upper_bound(v.begin(),v.end(),p);
       it--;
       if(it >= v.begin() && it->first <= q && q <= it->second) cout << "1 ";
       else cout << "0 ";
    }
}
