#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toLower(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 65 || s[i] <= 97){
            s[i] = tolower(s[i]);
        }
    }
    return s;
}

vector<string> ToVec(string s){
    vector<string> temp;
    int p = 0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ',' || i == s.size()){
            string t = s.substr(p, i-p);
            temp.push_back(toLower(t));
            p = i+1;
        }
    }
    return temp;
}

int main(){
    freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    vector<string> v = ToVec(s);
    // for(auto i: v){
    //     cout << i << endl;
    // }
    int max = 0;
    string last;
    for(auto i: v){
        map<char, int> mm;
        for(int j=0; j<i.size(); j++){
            mm[i[j]]++;
        }
        int cnt=0;
        for(auto k: mm){
            if(k.second >= 2) cnt++;
        }
        if(cnt > max){
            max = cnt;
            last = i;
        }
    }
    if(max == 0){
        cout << -1 << endl;
    }else{
        reverse(last.begin(), last.end());
        cout << last << endl; 
    }
    return 0;
}
