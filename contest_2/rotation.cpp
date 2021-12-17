#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    int threshold = t.size();
    while(s != t) {
        if (cnt > threshold) {
            cout << "Impossible";
            return 0;
        }
        rotate(t.begin(), t.begin() + 1, t.end());
        cnt++;
    }
    cout << cnt;

    return 0;
}