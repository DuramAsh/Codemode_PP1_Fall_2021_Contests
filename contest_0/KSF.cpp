#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    queue<pair<string, int> > q;
    while(n--){
        string s;
        int m;
        cin >> s >> m;
        q.push(make_pair(s, m));
    }
    int cnt = 0, mins = 0;
    vector<string> v;
    while(!q.empty()){
        q.front().second -= mins;
        if (q.front().second <= 0){
            v.push_back(q.front().first);
            cnt++;
        } else mins++;
        q.pop();
    }
    cout << cnt << '\n';
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }

    return 0;
}