#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    string s;
    vector<string> l1;
    vector<string> l2;
    vector<string> l3;

    for(int i=0; i<n; i++){
        cin >> s;
        v1.push_back(s);        
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> s;
        v2.push_back(s);
    }
    
    int k;
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> s;
        v3.push_back(s);
    }

    for(string i : v1){
        if(find(v2.begin(), v2.end(), i) == v2.end()){
            l1.push_back(i);
        }
    }
    for(string i : v2){
        if(find(v1.begin(), v1.end(), i) == v1.end()){
            l2.push_back(i);
        }
    }
    for(string i: v3){
        if(find(v2.begin(), v2.end(), i) != v2.end() && find(v1.begin(), v1.end(), i) != v1.end()){
            l3.push_back(i);
        }
    }

    if(l1.empty()){
        cout << -1 << endl;
    }else{
        for(auto i: l1){
            cout << i << " ";
        }
        cout << endl;
    }
    
    if(l2.empty()){
        cout << -1 << endl;
    }else{
        for(auto i: l2){
            cout << i << " ";
        }
        cout << endl;
    }
    
    if(l3.empty()){
        cout << -1 << endl;
    }else{
        for(auto i: l3){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}