#include <bits/stdc++.h>
using namespace std;

vector<int> items;

int main()
{
    int n,m,a,tmp;
    string cmd;
    cin >> n >> m >> a;
    priority_queue<pair<int,int>> pq[n];
    vector<map<int,int>> v(n);

    for(int i =0 ; i<n ; i++)
    {
        cin >> tmp;
        items.push_back(tmp);
    }
    for(int i =0 ; i<a; i++)
    {
        cin >> cmd;
        int U,I,V;
        if(cmd == "B")
        {
            cin >> U >> I >> V;
            v[I-1][U] = V;
        }
        else
        {
            cin >> U >> I;
            v[I-1].erase(U);
        }
    }

    for(int i =0 ; i<n;i++){
        for(auto &x : v[i]){
            pq[i].push({x.second,x.first-1});
        }
    }

    vector<vector<int>> ans(m);
    for(int i = 0 ; i< n ; i++){
        //cout << pq[i].top().first << " " << pq[i].top().second << endl;
        while(!pq[i].empty()&& items[i]--){
            ans[pq[i].top().second].push_back(i+1);
            pq[i].pop();
        }
    }

    for(int i = 0;i<m;i++){
        if(ans[i].empty()) cout << "NONE\n";
        else{
            for(auto y : ans[i]) cout << y << " ";
            cout << "\n";
        }
    }

}
