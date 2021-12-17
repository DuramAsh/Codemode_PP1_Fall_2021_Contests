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
#define INF (int)1e9
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

int main() {
#ifdef FREOPEN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;

    string s;
    char c;
    cin >> s >> c;
    vector<int> ind, pos(s.size(), INF);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) ind.pb(i);
    }

    for (int i = 0; i < ind.size(); ++i) {
        for (int j = 0; j < pos.size(); ++j) {
            pos[j] = min(pos[j], abs(ind[i] - j));
        }
    }

    for (auto i : pos) cout << i << sep;

    return 0;
}