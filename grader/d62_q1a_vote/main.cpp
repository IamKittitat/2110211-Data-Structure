#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    map<string,int> cdd;
    vector<int> scr;
    cin >> n >> k;
    for(int i =0 ;i<n;i++){
        string name;
        cin >> name;
        if(cdd.find(name) != cdd.end()){
            cdd[name]++;
        } else{
            cdd[name]=1;
        }
    }
    for(auto &x : cdd){
        scr.push_back(x.second);
    }
    sort(scr.begin(),scr.end());
    int pos = scr.size() < k ? 0 : scr.size()-k;
    cout << scr[pos];

}
