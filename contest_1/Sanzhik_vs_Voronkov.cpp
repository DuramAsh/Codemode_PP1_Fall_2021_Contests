#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int questions, q_time, amount, cnt = 0;
    cin >> questions >> q_time >> amount;
    while(amount--) {
        int quiz;
        cin >> quiz;
        int solved = quiz / q_time;
        if (solved >= 10) {
            cnt += 10;
        } else cnt += solved;
    }
    if (cnt >= questions) {
        cout << "Stipuha est' - mozhno poest'\n";
    } else cout << "Voronkov chert!\n";
    cout << cnt;

    return 0;
}