#include <bits/stdc++.h>
using namespace std;
int main(){   
    int n; cin >> n;
    map<int, int> m;
    vector<int> u, d;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        m[x]++;
    }
    for(auto i : m){
        if(i.second == 1){
            u.push_back(i.first);
        }else{
            d.push_back(i.first);
        }
    }

    if(u.size() == 0){
        cout << "Zvonite mamam, u vas retaki" << endl;
    }else{
        cout << "}{orishie: ";
        for(auto i : u){
            cout << i << " ";
        }
        cout << endl;
    }

    if(d.size() == 0){
        cout << "Molodcy" << endl;
    }else{
        cout << "Plo}{ie: ";
        for(auto i : d){
            cout << i << " ";
        }
    }
}