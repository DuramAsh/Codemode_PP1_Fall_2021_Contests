#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

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

int ar[1001];

int fib(int n) {
    if (n == 1) return ar[1] = 0;
    if (n == 2) return ar[2] = 1;
    return ar[n] = ((ar[n - 1] % 10) + (ar[n - 2] % 10)) % 10;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    IOS;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << fib(i) << sep;
    }    

    return 0;
}