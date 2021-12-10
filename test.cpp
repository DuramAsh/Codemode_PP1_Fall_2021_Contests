#include <bits/stdc++.h>
using namespace std;

int main(){

    int ar[101];
    ar[0] = 0;
    ar[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        ar[i] = (ar[i - 1] % 10 + ar[i - 2] % 10) % 10;
    }

    for (auto i : ar) {
        cout << i << endl;
    }

    return 0;
}