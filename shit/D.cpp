#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> v, int n) {
    n--;
    cout << n << ' ' << v[n] << endl;
    if (n == 0) {
        return v[n];
    }
    int max = findMax(v, n);
    cout << max << endl;
    if (v[n] > max) {
        return v[n];
    }
    return max;
}

int main(){

    vector<int> v = {12, 43, 55, 11, 2, 4123, 321};
    cout << findMax(v, v.size());

    return 0;
}