#include <bits/stdc++.h>
using namespace std;

#define ls st << 1
#define rs st << 1 | 1
#define fst first
#define snd second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define VI vector<int>
#define CLR(a, b) memset(a, (b), sizeof(a))
#define ALL(x) x.begin(), x.end()
#define ber(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, s, e) for (int i = (s); i >= (e); i--)

const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-8;

void fe()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
LL read()
{
    LL x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    return x * f;
}

struct edge
{
    int v, cost;
    edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<edge> E[MAXN];
void addedge(int u, int v, int w)
{
    E[u].push_back(edge(v, w));
    E[v].push_back(edge(u, w));
}
bool vis[MAXN];
int dis[MAXN];

void SPFA(int s, int n)
{
    CLR(vis, false);
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    vis[s] = true;
    dis[s] = 0;
    queue<int> que;
    while (!que.empty())
        que.pop();
    que.push(s);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[u][i].v;
            int cost = E[u][i].cost;
            if (dis[v] > dis[u] + cost)
            {
                dis[v] = dis[u] + cost;
                if (!vis[v])
                {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}

bool mps[MAXN][MAXN];
int main()
{
    CLR(mps, false);
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addedge(u, v, 1);
        mps[u][v] = mps[v][u] = true;
    }
    int ans1, ans2;
    SPFA(1, n);
    ans1 = dis[n];
    for (int i = 1; i <= n; i++)
        E[i].clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (!mps[i][j])
            {
                mps[i][j] = true;
                addedge(i, j, 1);
                addedge(j, i, 1);
            }
        }
    }
    SPFA(1, n);
    ans2 = dis[n];
    if (ans1 == INF || ans2 == INF)
        cout << -1 << endl;
    else
        cout << max(ans1, ans2) << endl;
    return 0;
}