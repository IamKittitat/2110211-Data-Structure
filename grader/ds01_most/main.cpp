#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,max_word = 0;
    string word;
    pair<string,int> ans;
    map<string,int> words;
    cin >> n;
    for(int i = 0; i<n;i++){
        cin >> word;
        if(words.find(word) != words.end()){
            words[word]++;
        } else{
            words[word] = 1;
        }
    }
    for(auto &x : words){
        if(x.second >= max_word){
            ans = x;
            max_word = x.second;
        }
    }
    cout << ans.first << " " << ans.second;
}
