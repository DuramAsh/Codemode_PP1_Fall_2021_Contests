#include <bits/stdc++.h>
using namespace std;

void low (string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (65 <= s[i] && s[i] <= 90) s[i] += 32;
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    low(s);
    map<char, int> m;
    map<char, int> :: iterator it;
    for (int i = 0; i < s.size(); ++i ) {
        m[s[i]]++;
    }
    int cnt = 0;
    for (it = m.begin(); it != m.end(); ++it) {
        switch (it->first) {
            case 'p':
            case 'a':
            case 'c':
            case 'i':
            case 'f':
            case 'y':
            case 'w':
            case 'n':
            case 'e':
                if (it->second > 0 && it->first != 'i') {
                    cnt++;
                } else if (it->first == 'i' && it->second > 1) cnt++;
            default:
                continue;
        }
    }
    cout << (cnt == 9 ? "Bubu": "Wine by");
    return 0;
}