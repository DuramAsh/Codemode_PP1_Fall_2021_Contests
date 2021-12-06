#include <bits/stdc++.h>
using namespace std;
int si, sj, fi, fj;
char maze[10][10];
bool found;

void dfs(char maze[][10], int i, int j) {
    if (i == fi && j == fj) {
        found = true;
    }
    
    if (i < 0 || i >= 10 || j < 0
    || j >= 10 || maze[i][j] == '*') return;

    maze[i][j] = '*';

    dfs(maze, i - 1, j);
    dfs(maze, i + 1, j);
    dfs(maze, i, j + 1);
    dfs(maze, i, j - 1);
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> maze[i][j];
        }
    }
    cin >> si >> sj >> fi >> fj;
    dfs(maze, si, sj);
    cout << (found ? "Found))" : "Not found((");

    return 0;
}