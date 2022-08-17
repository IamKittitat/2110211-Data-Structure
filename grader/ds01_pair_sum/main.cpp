#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,tmp;
    bool found;
    set<int> s;
    vector<int> v;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
        v.push_back(tmp);
    }
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        for(int j = 0 ; j < v.size() ; j++){
            auto pos = s.find(tmp-v[j]);
            if(pos != s.end() && s.find(v[j]) != pos)
            {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if(!found)
        {
            cout << "NO" << endl;
        }
        found = false;
    }
}
