#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    long long ip1,ip2,ft1,ft2,gft1,gft2;
    cin >> n >> m;
    map <long long,long long> relation;
    for(int i=0; i<n; i++)
    {
        cin >> ip1 >> ip2;
        relation[ip2] = ip1;
    }
    for(int i = 0; i<m; i++)
    {
        cin >> ip1 >> ip2;
        if(ip1 == ip2) cout << "NO\n";
        else
        {
            if(relation.find(ip1) != relation.end())
            {
                ft1 = relation[ip1];
            } else{
                cout << "NO\n";
                continue;
            }
            if(relation.find(ip2) != relation.end())
            {
                ft2 = relation[ip2];
            } else{
                cout << "NO\n";
                continue;
            }
            if(relation.find(ft1) != relation.end() && relation.find(ft2) != relation.end() && relation[ft1] == relation[ft2])
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

}
