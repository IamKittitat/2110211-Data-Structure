#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,f,s,c,l,cor;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> f >> s >> c >> l >> cor;
        bool ok = false;
        if(c != 0 && (f+s)%c==l && s <= c && l < c && f < c) ok = true;
        if(ok) cout << "OK ";
        else cout << "WRONG ";
        if(!ok && cor != 0){
            int ans;
            switch(cor){
            case(1):
                cout << (l-s+c)%c;
                break;
            case(2):
                cout << (l+c-f)%c;
                break;
            case(3):
                if(f < l) cout << l+1;
                else cout << f+s-l;
                break;
            case(4):
                cout << (f+s)%c;
                break;
            }
        }
        cout << "\n";
    }
}

/*
10
0 0 1 0 0
0 2 4 2 0
0 8 8 20 0
0 2 4 0 0
0 2 4 0 2
0 2 4 0 4
1 3 8 7 1
10 100 8 110 3
3 8 2 3 3
3 2 0 5 3
*/
