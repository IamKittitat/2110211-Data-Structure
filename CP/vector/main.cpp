#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    CP::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    CP::vector<int> v2(v);
    cout << v.size() << " " << v.capacity() << " " << v.empty() << endl;
    for(auto &x : v)cout << x << " " ;
    cout << endl;
    v.insert(v.begin()+1,100);
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
    v.erase(v.end()-1);
    cout << v[0] << " " << v[1] << endl;
    v.resize(1);
    for(auto &x : v)cout << x << " " ;
}
