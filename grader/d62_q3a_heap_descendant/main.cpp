#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin >> n >> a;
    queue<int> q;
    queue<int> ans;
    int total = 0;
    q.push(a);
    while(!q.empty()){
        ans.push(q.front());
        total++;
        int lc = 2*q.front()+1;
        int rc = 2*q.front() +2;
        q.pop();
        if(lc < n) q.push(lc);
        if(rc < n) q.push(rc);
    }
    cout << total << endl;
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}
