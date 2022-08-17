#include <bits/stdc++.h>

using namespace std;

vector<int> reverse(vector<int> v){
    vector<int> tmp;
    for(int i= v.size()-1;i>=0;i--){
        tmp.push_back(v[i]);
    }
    return tmp;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0 ;i < n;i++){
        string cmd;
        int nb;
        cin >> cmd;
        if(cmd == "pb"){
            cin >> nb;
            v.push_back(nb);
        } else if(cmd == "sa"){
            sort(v.begin(),v.end());
        } else if(cmd == "sd"){
            sort(v.begin(),v.end());
            v = reverse(v);
        } else if(cmd == "r"){
            v = reverse(v);
        } else if(cmd == "d"){
            cin >> nb;
            v.erase(v.begin() + nb);
        }
    }
    for(int i = 0 ; i< v.size();i++){
        cout << v[i] << " ";
    }

}
