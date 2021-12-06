#include <bits/stdc++.h>
using namespace std;

void print(vector<int> & v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void make_big(int & a){
    a += a; 
}

int main(){
    freopen("input2.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }   
    cout << "initial ";
    print(v);
    int m; cin >> m;
    for(int i = 1; i <= m; ++i){
        string s; cin >> s;
        if(s == "sort"){
            sort(v.begin(), v.end());
            cout << i <<") ";
            print(v);
        }else if(s == "reverse"){
            reverse(v.begin(), v.end());
            cout << i <<") ";
            print(v);
        }else if(s == "find_max"){
            auto k = max_element(v.begin(), v.end());
            cout << i << ") ";
            print(v);
            cout << "max - " << *k << endl;
        }else if(s == "find_min"){
            auto k = min_element(v.begin(), v.end());
            cout << i << ") ";
            print(v);
            cout << "min - " << *k << endl;
        }else if(s == "sum"){
            int sum = accumulate(v.begin(), v.end(), 0);
            cout << i << ") ";
            print(v);
            cout << "sum - " << sum << endl;
        }else if(s == "kick_one"){
            int which;
            cin >> which;
            v.erase(v.begin() + which);
            cout << i <<") ";
            print(v); 
        }else if(s == "kick_part"){
            int from, where;
            cin >> from >> where;
            v.erase(v.begin() + from,v.begin() + where);
            cout << i << ") ";
            print(v);
        }else if(s == "kick_all"){
            v.clear();
            cout << i << ") ok" << endl;
        }else if(s == "how_many"){
            int who;
            cin >> who;
            int cnt = count(v.begin(),v.end(), who);
            cout << i << ") ";
            print(v);
            cout << cnt <<" times" << endl;
        }else if(s == "make_bigger"){
            for_each(v.begin(),v.end(),make_big);
            cout << i << ") ";
            print(v);
        }else if(s == "invite_one"){
            int who, where;
            cin >> who >> where;
            v.insert(v.begin() + where, who);
            cout << i << ") ";
            print(v);
        }
    }
}