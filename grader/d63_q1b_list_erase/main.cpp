#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void list_erase(vector<int> &v, vector<int> &pos)
{
    vector<int> tmp;
    set<int> set_pos;
    for(auto &x : pos) set_pos.insert(x);
        for(int i = 0;i<v.size();i++){
         if(set_pos.find(i) == set_pos.end()){
            tmp.push_back(v[i]);
            set_pos.erase(i);
         }
     }
     v = tmp;
    // vector<int> tmp;
    // sort(pos.begin(),pos.end());
    // int tmp_pos = 0;
    // for (int i = 0; i<v.size();i++){
    //     if(i != pos[tmp_pos]) tmp.push_back(v[i]);
    //     else if(i >= pos[tmp_pos] && tmp_pos+1 < pos.size()) tmp_pos++;
    // }
    v = tmp;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> pos[i];
    list_erase(v,pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}
