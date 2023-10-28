#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> money;
vector<pair<int, int>> v;
vector<int> totalMoney(100005);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, start, a, S, P, x;

    cin >> n >> m >> start;
    v.push_back(pair<int, int>(0, start));
    money.push_back(start);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> S;
        v.push_back(pair<int, int>(a, S));
    }

    sort(v.begin(), v.end());

    int idx = 0;
    int money = 0;
    for (int i = 0; i < 100005; i++)
    {
        if (idx <= n && i == v[idx].first)
        {
            start = v[idx].second;
            idx++;
        }
        money += start;
        totalMoney[i] = money;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> P >> x;
        if (P <= totalMoney[x])
        {
            cout << lower_bound(totalMoney.begin(), totalMoney.end(), P) - totalMoney.begin() << " ";
        }
        else
        {
            cout << lower_bound(totalMoney.begin(), totalMoney.end(), P + totalMoney[x]) - totalMoney.begin() << " ";
        }
    }
}