#include <bits/stdc++.h>

using namespace std;

bool findRelation(int child,int ancestor){
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        queue<int> q;
        int a,b;
        int ans = false;
        cin >> a >> b;
        if(a == b){
            cout << "a and b are the same node\n";
            ans = true;
        }
        else if(a >b){
            q.push(b);
            while(!q.empty()){
                int lc = q.front()*2+1, rc = q.front()*2+2; q.pop();
                if(lc == a || rc == a ){
                    cout << "b is an ancestor of a\n";
                    ans = true;
                    break;
                }
                if(lc < a) q.push(lc);
                if(rc < a) q.push(rc);
            }
        }
        else{
            q.push(a);
            while(!q.empty()){
                int lc = q.front()*2+1, rc = q.front()*2+2; q.pop();
                if(lc == b || rc == b ){
                    cout <<  "a is an ancestor of b\n";
                    ans = true;
                    break;
                }
                if(lc < b) q.push(lc);
                if(rc < b) q.push(rc);
            }
        }
        if(!ans) cout << "a and b are not related\n";
    }
}
