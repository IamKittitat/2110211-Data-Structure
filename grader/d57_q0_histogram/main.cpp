#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> m;
    int n;
    string tmp;
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> tmp;
        m[tmp]++;
    }
    for(auto &x : m){
        if(x.second > 1){
            cout << x.first << " " << x.second << endl;
        }
    }
}
