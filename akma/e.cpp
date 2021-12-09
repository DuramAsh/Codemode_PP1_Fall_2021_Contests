#include <bits/stdc++.h>

using namespace std;

int n, m, pr[200005], answer[200005];
vector<int> g[200005];

int get(int v)
{
    if (pr[v] == v)
        return v;
    return pr[v] = get(pr[v]);
}

int main()
{
    cin >> n >> m;
    int i = 1;
    while (i <= m)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
        {
            g[x].push_back(y);
        }
        else
        {
            g[y].push_back(x);
        }
        ++i;
    }
    for (int i = 1; i <= n; i++)
    {
        pr[i] = i;
    }
    int current = n;
    for (int i = n; i >= 1; i--)
    {
        answer[i] = current;
        for (auto j : g[i])
        {
            int x = i, y = j;
            x = get(x), y = get(y);
            if (x == y)
                continue;
            current--;
            pr[x] = y;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] - i << '\n';
    }
    return 0;
}