#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,f,s,c,l,cor;
    cin >> n;
    for(int i = 0 ; i < n ;i++){
        cin >> f >> s >> c >> l >> cor;
        bool correct = false;
        if(c!=0 && (f+s)%c == l && l < c && s <= c && f < c) correct = true;
        if(correct) cout << "OK ";
        else cout << "WRONG ";
        if(!correct && cor){;
            switch(cor){
            case(1):
                cout << (l-s+c)%c;
                break;
            case(2):
                cout << (l-f+c)%c;
                break;
            case(3):
                if(f<l) cout << l+1;
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

