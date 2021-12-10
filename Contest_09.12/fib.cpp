#include <bits/stdc++.h>
using namespace std;

int ar[1001];
int fib(int n) {
    if (n == 1) return ar[1] = 0;
    if (n == 2) return ar[2] = 1;
    return ar[n] = ((ar[n - 1] % 10) + (ar[n - 2] % 10)) % 10;
}

int main(){
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cout << fib(i) << " ";
    // 0 1 1 2 3 5 8 13 21 34 55 89 144
    return 0;
}