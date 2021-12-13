#include <iostream>
#include <sstream>
using namespace std;
typedef long long ll;
string sum (string s ) {
    stringstream ss;
    string k;
    int a;
    for(size_t i = 0; i < s.size(); i++)a+=s[i]-'0';
    ss << a;
    ss >> k;
    return k;
}
int main() {
    string s; cin >> s;
    if (s.size() == 1) {
        cout << s << ' ' << 0;
        return 0;
    }
    string t = sum (s);
    int cnt = 1;
    if (t.size() == 1) {
        cout << t << ' ' << 1;
    }
    else {
        while (t.size()!=1) {
            t = sum(t);
            cnt++;
            cout << t << ' ' << cnt << endl;
        }
    }
    return 0;
}