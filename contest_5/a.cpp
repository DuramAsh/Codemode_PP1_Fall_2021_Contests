#include <iostream>
#include <queue>

using namespace std;

char a[100][100];
int n, m;
queue<pair<int, int> > q;

void filll(int v, int x, int y){
    if (x >= 0 && y >= 0 && x < m && y < m){
        if(a[x][y] == ' '){
            a[x][y] = char(v);
            q.push(make_pair(x, y));
        }
    }
}


int main(){
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = n * 2 - 1;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            a[i][j] = ' ';
        }
    }
    a[n-1][n-1] = 'a';
    
    q.push(make_pair(n-1, n-1));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        if(int(a[x][y]-96) == n) break;
        q.pop();
        filll(int(a[x][y]) + 1, x+1, y);
        filll(int(a[x][y]) + 1, x-1, y);
        filll(int(a[x][y]) + 1, x, y+1);
        filll(int(a[x][y]) + 1, x, y-1);
    }


    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == ' '){
                cout << '-';
            }else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}