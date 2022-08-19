#include <bits/stdc++.h>

using namespace std;

map<int,pair<int,int>> subject;
map<string,pair<int,int>> prof;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << std::fixed << std::setprecision(2);

    int n,id,scr;
    string name;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> id >> name >> scr;
        if(subject.find(id) != subject.end()){
            subject[id].first+=scr;
            subject[id].second++;
        } else{
            subject[id].first = scr;
            subject[id].second = 1;
        }
        if(prof.find(name) != prof.end()){
            prof[name].first+=scr;
            prof[name].second++;
        } else{
            prof[name].first = scr;
            prof[name].second = 1;
        }
    }
    for(auto &x : subject){
        cout << x.first << " " << (x.second.first +0.0)/x.second.second << "\n";
        //cout << x.first << " " << x.second.first << " " << x.second.second << endl;
    }
    for(auto &x : prof){
        cout << x.first << " " << (x.second.first +0.0)/x.second.second << "\n";
    }
}
