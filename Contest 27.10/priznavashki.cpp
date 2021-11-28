#include <iostream>
#include <map>
using namespace std;

bool check(string s1, string s2){
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < s1.length();i++){
        if(int(s1[i]) % 2 == 0){
            cnt1++;
        }
    }
    for(int i = 0; i < s2.length();i++){
        if(int(s2[i]) % 2 == 0){
            cnt2++;
        }
    }
    return cnt1 == cnt2;
}

int main(){
    int n; cin >> n;
    map<pair<string, string>, string> m;
    for(int i = 0; i < n; i++){
        string who, whom;
        cin >> who >> whom;
        if(check(who, whom)){
            m[make_pair(who, whom)] = "LOVE!";
        }else{
            m[make_pair(who, whom)] = "Nu shto ty bratishka pritih?";
        }
    }

    map<pair<string, string>, string> :: iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        cout << it->first.first << " + " << it->first.second << " = " << it->second << endl;
    }
}   