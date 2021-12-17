#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <iomanip>

using namespace std;

#define FREOPEN
#define sz(x) x.size()
#define INF (int)1e9
#define MAXN (int)1e6
#define MAX (int)2147483647
#define MIN (int)-2147483648
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fst first
#define snd second
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long
#define sep ' '
#define VI vector<int>
#define VB vector<bool>

string concat(string &s, string &t){
    int i = min(sz(s), sz(t)), cnt = i;
    while(s.substr(sz(s) - i, i) != t.substr(0, i)){
        cnt = --i;
    }
    while(cnt--){
        t.erase(0, 1);
        s.erase(sz(s) - 1, 1);
    }
    return s + t;
}

int main() {
#ifdef FREOPEN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;

    string s, t;
    cin >> s >> t;
    cout << concat(s, t);

    return 0;
}