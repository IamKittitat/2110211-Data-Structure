#include<bits/stdc++.h>

using namespace std;
vector<int> p;
vector<int> fpt;
vector<int> dm;
vector<int> salary;

int main()
{
    int n,m,tmp,cmd,a,b;
    size_t idx_fpt=0,idx_dm=0;
    cin >> n >> m ;
    for(int i = 0; i<m; i++)
    {
        cin >> tmp;
        p.push_back(tmp);
    }
    for(int i = 0; i<n; i++)
    {
        cin >> cmd;
        if(cmd == 1)
        {
            cin >> a >> b;
            if(a == 1) fpt.push_back(b);
            else dm.push_back(b);
        }
        else
        {
            int m_fpt = INT_MAX, m_dm = INT_MAX;
            int tmp_ans = salary.size() == 0 ? 0 : salary[salary.size()-1];
            if(idx_fpt < fpt.size()) m_fpt = fpt[idx_fpt];
            if(idx_dm < dm.size()) m_dm = dm[idx_dm];

            if(m_fpt <= m_dm){
                idx_fpt++;
                tmp_ans += m_fpt;
            } else{
                idx_dm++;
                tmp_ans += m_dm;
            }
            salary.push_back(tmp_ans);
        }
    }

    for(int i = 0;i<m;i++){
        int want = p[i];
        auto it = lower_bound(salary.begin(),salary.end(),want);
        if(it == salary.end()) cout << "-1 ";
        else cout << it-salary.begin() + 1 << " ";
    }
}
