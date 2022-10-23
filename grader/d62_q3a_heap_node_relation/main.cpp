#include <bits/stdc++.h>

using namespace std;

bool findRelation(int child,int ancestor){
    while(child > ancestor){
        child = (child-1)/2;
        if(child == ancestor) return true;
    }
    return false;
}

int main()
{
   int n,m;
   cin >> n >> m;
   for(int i=0;i<m;i++){
        int a,b;
        bool ans = false;
        cin >> a >> b;
        if(a==b){
           cout << "a and b are the same node\n";
           ans = true;
        }
        else if(a>b){
            ans =  findRelation(a,b);
            if(ans) cout << "b is an ancestor of a\n";
        }
        else if(a<b){
            ans =  findRelation(b,a);
            if(ans) cout << "a is an ancestor of b\n";
        }

        if(!ans) cout << "a and b are not related\n";
   }
}
