#include <bits/stdc++.h>

using namespace std;
map<int,int> card;

int main()
{
    int n,m,tmp,r,op;
    int ans = 1;
    cin >> n >> m;
    for (int i = 0 ; i<n ;i++){
        cin >> tmp;
        card[tmp]++;
    }
    for(int i = 0 ; i<m ;i++){
        cin >> r;
        for (int j =0;j<r;j++){
            cin >> op;
            auto it = card.upper_bound(op);
            if(it == card.end()){
                cout << ans;
                exit(0);
            }
            it->second--;
            if(it->second == 0) card.erase(it->first);
        }
        ans++;
    }
    cout << yns;
}
