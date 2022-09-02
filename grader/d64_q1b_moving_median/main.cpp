#include <bits/stdc++.h>

using namespace std;
vector<int> v1;
vector<int> v2;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w,tmp;
    cin >> n >> w;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        v1.push_back(tmp);
        if(i <= w) v2.push_back(v1[i]);
    }
    for(int i = 0; i< n - w ; i++){
        sort(v2.begin(),v2.end());
        //cout << "CHECK " << v[i] << endl;
        //for(auto &x : v2) cout << "IN" << x << " " << endl;
        cout << v2[w/2] << " ";
        for(int j = 0 ; j < v2.size();j++) {
            if(v2[j] == v1[i]){
                v2.erase(v2.begin()+j);
                break;
            }
        }
        if(i+w+1 < v1.size()) v2.push_back(v1[i+w+1]);
    }
}
