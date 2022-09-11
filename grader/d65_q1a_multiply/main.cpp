#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v,
                     vector<pair<vector<int>::iterator,int>> &multiply)
{
//write your code here
    vector<int> tmp;
    int idx = 0;
    sort(multiply.begin(),multiply.end());
    for(auto it = v.begin() ; it!=v.end();it++){
        if(it == multiply[idx].first){
            for(int j=0;j<multiply[idx].second+1;j++) tmp.push_back(*it);
            idx++;
        } else{
            tmp.push_back(*it);
        }
    }
    v = tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
