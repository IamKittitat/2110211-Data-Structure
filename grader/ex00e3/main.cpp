#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,tmp;
    set<int> s;
    cin >> n;
    for(int i =0 ;i < n; i++){
        cin >> tmp;
        if(s.find(tmp) == s.end()){
            s.insert(tmp);
        } else{
            cout << "NO";
            exit(0);
        }
    }
    for(int i = 1; i< n ; i++){
        if(s.find(i) == s.end()){
            cout<<"NO";
            exit(0);
        }
    }
    if(s.size() != n) {
        cout << "NO";
        exit(0);
    }
    cout << "YES";
}
