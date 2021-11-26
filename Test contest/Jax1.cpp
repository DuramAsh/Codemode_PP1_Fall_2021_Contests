#include <bits/stdc++.h>
using namespace std;

long long degree(string q, string w){
    int s1 = 0, s2 = 0;
    for (int i = 0; i < q.size(); ++i){
        s1 += int(q[i]);
    }
    for (int i = 0; i < w.size(); ++i){
        s2 += int(w[i]);
    }
    return s1 - s2;
}

bool comp(pair<pair<string, string>, int> &p1, pair<pair<string, string>, int> &p2){
    if (p1.second == p2.second){
        if (p1.first.first == p2.first.first){
            return p1.first.second < p2.first.second;
        }
        return p1.first.first < p2.first.first;
    }
    return p1.second > p2.second;
}

int main(){
    // freopen("inputJ1.txt", "r", stdin);
    map<pair<string, string>, int> m;
    int n;
    cin >> n;
    while (n--){
        string fname, lname;
        cin >> fname >> lname;
        m[make_pair(fname, lname)] = degree(fname, lname);
    }
    vector<pair<pair<string, string>, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    for (auto &i : v){
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
    }

    return 0;
}