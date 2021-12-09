#include <bits/stdc++.h>

using namespace std;

int n, m, k, t[505];
vector<int> e[505];

void dfs(int x)
{
    t[x] = 1;
    for (int to : e[x])
    {
        if (!t[to])
        {
       dfs(to);
        }
        else if (t[to] == 1)
            k++;
    }
    //cout << k << '\n';
    //cout << t[x] << '\n';
    t[x] = 2;
}

void fill()
{
    for (int j = 1; j <= n; ++j)
        t[j] = 0;
}

bool solve()
{
    for (int i = 0; i < n; i++)
    {
        k = 0;
        fill();
        dfs(i);
        for (int j = 1; j <= n; j++)
        {
            if (!t[j])
                dfs(j);
        }
        //cout << k << '\n';
        if (k <= 1)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    if (solve())
        cout << "YES";
    else
        cout << "NO";
}