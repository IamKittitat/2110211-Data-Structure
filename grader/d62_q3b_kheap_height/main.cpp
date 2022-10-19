#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,total = 0,i=0;
    cin >> n >> k;
    long long tmp = 1;
    if(k == 1)
    {
        cout << n-1;
    }
    else
    {
        while(total <n)
        {
            total += tmp;
            tmp *=k;
            i++;
        }
        cout << i-1;
    }

}
