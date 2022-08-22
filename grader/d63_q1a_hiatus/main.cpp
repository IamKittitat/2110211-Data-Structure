#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,yr,mo;
    vector<pair<int,int>> v;
    pair<int,int> date;
    cin >> n >> m;
    for(int i = 0 ; i<n; i++)
    {
        cin >> yr >> mo;
        date = {yr,mo};
        v.push_back(date);
    };
    sort(v.begin(),v.end());
    for( int i = 0; i<m; i++)
    {
        cin >> yr >> mo;
        date = {yr,mo};
        auto it = lower_bound(v.begin(),v.end(),date);
        if(*it == date) cout << "0 0 ";
        else if(*it > date || it == v.end())
        {
            if(it == v.begin()) cout << "-1 -1 ";
            else{
                it--;
                cout << it->first << " " << it->second << " ";
            }
        }

    }
}

