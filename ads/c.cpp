#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std ;

const int MAXN = 2e5 + 1;
int n, m, used[MAXN];
vector<int> g[MAXN], cycle;
bool isCycle = false;

void dfs(int v) {
    used[v] = 1;
    for( int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if( used[to] == 0) {
            cycle.pb(to);
            dfs(to);
            if( isCycle == true)
                return;
        }
        else if (used[to] == 1) {
            isCycle = true;
            return;
        }
    }
    cycle.pop_back();
    used[v] = 2;
}
void dfs(int v, int l, int r) {
    used[v] = 1;
    for( int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if( v == l && to == r)
            continue;
        if( used[to] == 0) {
            dfs(to, l, r);
            if( isCycle == true)
                return;
        }
        else if (used[to] == 1) {
            isCycle = true;
            return;
        }
    }
    used[v] = 2;
}
int main()
{
    cin >> n >> m;
    for( int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        if(x == y) {
            cycle.pb(x);
            cycle.pb(y);
            isCycle = true;
        }
    }
    if( isCycle == false) {
        for( int i = 1; i <= n; ++i) {
            if( !used[i]) {
                cycle.pb(i);
                dfs(i);
                if( isCycle == true) {
                    break;
                }
            }
        }
    }
    if( isCycle == false) {
        cout << "YES";
        return 0;
    }
    for( int j = 1; j < cycle.size(); ++j) {
        int l = cycle[j - 1], r = cycle[j];
        isCycle = false;
        for( int i = 1; i <= n; ++i)
            used[i] = 0;
        for( int i = 1; i <= n; ++i) {
            if(!used[i]) {
                dfs(i, l, r);
                if( isCycle)
                    break;
            }
        }
        if( isCycle == false) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}