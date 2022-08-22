#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,k;
    vector<int> v;
    cin >> n >> m >> k;
    for(int i = 0 ; i< n ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i = 0 ; i< m ; i++){
        int tmp,ans = 0;
        cin >> tmp;
        auto first_it = lower_bound(v.begin(),v.end(),tmp-k);
        auto last_it = lower_bound(v.begin(),v.end(),tmp+k);
        if(*last_it > tmp+k) last_it--;
        cout << last_it - first_it + 1 << " ";
    }
}
