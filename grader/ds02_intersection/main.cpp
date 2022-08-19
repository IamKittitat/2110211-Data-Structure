#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,input;
    cin >> n >> m;
    vector<int> v1,v2,ans;
    for(int i = 0; i<n;i++){
        cin >> input;
        v1.push_back(input);
    }
    for(int i = 0; i<m;i++){
        cin >> input;
        v2.push_back(input);
    }
    for(auto &x : v1){
        if(find(v2.begin(),v2.end(),x) != v2.end() && find(ans.begin(),ans.end(),x) == ans.end()){
            ans.push_back(x);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto &x : ans){
        cout << x << " ";
    }
}
