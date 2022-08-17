#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it,int k){
    for(int i = k ; i>= -k ;i--){
        if((it+i) < v.end() && (it+i) >= v.begin()){
            v.erase(it+i);
        }
    }
    return v;
}
int main()
{
    int n,j,k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}
