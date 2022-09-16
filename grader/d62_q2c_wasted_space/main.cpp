#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ip;
    cin >> ip;
    vector<int> v;
    int x = 1;
    while(x < ip) x*=2;
    cout << x-ip;
}
