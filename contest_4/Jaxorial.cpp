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

ull factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int compress(ull n) {
    if (n < 10) return n;
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return compress(sum);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cout << factorial(i) << sep << compress(factorial(i)) << endl;
    }

    return 0;
}