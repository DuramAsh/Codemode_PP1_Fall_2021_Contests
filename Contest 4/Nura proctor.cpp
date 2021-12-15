#include <bits/stdc++.h>
using namespace std;
int main(){   
    int n; cin >> n;
    map<int, int> m;
    vector<int> u;
    vector<int> d;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        m[x]++;
    }
    map<int, int> :: iterator i;
    for(i = m.begin(); i != m.end(); i++){
        if((*i).second == 1){
            u.push_back((*i).first);
        }else{
            d.push_back((*i).first);
        }
    }

    if(u.size() == 0){
        cout << "Zvonite mamam, u vas retake" << endl;
    }else{
        cout << "}{orishie: ";
        for(int i = 0; i < u.size(); i++){
            cout << u[i] << " ";
        }
        cout << endl;
    }

    if(d.size() == 0){
        cout << "Molodcy" << endl;
    }else{
        cout << "Plo}{ie: ";
        for(int i = 0; i < d.size(); i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
}