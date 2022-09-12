#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,tmp;
    int time = 0;
    cin >> n >> m;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        pq.push(make_pair(0,tmp));
    }
    while(m>0)
    {
        cout << time << "\n";
        pair<int,int> tmp_p;
        if(!pq.empty())
        {
            tmp_p = pq.top();
            pq.pop();
        }
        tmp_p.first -= tmp_p.second;
        pq.push(tmp_p);
        m--;
        time= -pq.top().first;
    }
}
