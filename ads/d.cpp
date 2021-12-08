#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n, m;
    cin >> n >> m;
    int used[n+1][n+1];
    vector<int> v[n+1], w[n+1];
    for( int i = 1; i <= n; ++i)
        for( int j = 1; j <= n; ++j) {
            if (i == j)
                used[i][j] = 1;
            else
                used[i][j] = -1;
        }
    while(m--) {
        int U, V;
        cin >> U >> V;
        used[U][V] = 1;
        used[V][U] = 1;
        v[U].push_back(V);
        v[V].push_back(U);
    }
    for( int i = 1; i <= n; ++i) {
        for( int j = 1; j <= n; ++j) {
            if( used[i][j] == -1) {
                w[i].push_back(j);
            }
        }
    }
    int bfs[n+1];
    for( int i = 1; i <= n; ++i)
        bfs[i] = -1;
    bfs[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for( int i = 0; i < v[cur].size(); ++i) {
            int to = v[cur][i];
            if( bfs[to] == -1) {
                bfs[to] = bfs[cur] + 1;
                q.push(to);
            }
            else if( bfs[to] > bfs[cur] + 1) {
                bfs[to] = bfs[cur] + 1;
                q.push(to);
            }
        }
    }
    if( bfs[n] == -1) {
        cout << -1;
        return 0;
    }
    int ans = bfs[n];
    for( int i = 1; i <= n; ++i)
        bfs[i] = -1;
    bfs[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for( int i = 0; i < w[cur].size(); ++i) {
            int to = w[cur][i];
            if( bfs[to] == -1) {
                bfs[to] = bfs[cur] + 1;
                q.push(to);
            }
            else if( bfs[to] > bfs[cur] + 1) {
                bfs[to] = bfs[cur] + 1;
                q.push(to);
            }
        }
    }
    if( bfs[n] == -1) {
        cout << -1;
        return 0;
    }
    ans = max(ans, bfs[n]);
    cout << ans;
}