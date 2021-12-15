#include <iostream>
#include <map>
using namespace std;

char cypher(int cnt){
    return ('a' + cnt % 26);
}

int main(){

    map<char, int> m;
    string s; cin >> s;
    for(int i = 0; i < s.size(); ++i){
        m[s[i]] = m[s[i]] + 1;
        //m[s[i]]++;
    }

    map<char, int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        cout << it->first << cypher(it->second);
    }


}
