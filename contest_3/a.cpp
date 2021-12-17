#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool Unique(string s, int n){
    map<char, int> m;
    map<char, int> :: iterator it;
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    int x = m[s[0]];
    for(it = m.begin(); it != m.end(); it++){
        if((*it).second != x){
            return false;
        }
    }
    return true;

}

int main(){
    freopen("input.txt", "r", stdin);
    
    string s;
    cin >> s;
    int n;
    cin >> n;

    if(!Unique(s, n) || s.size() % n != 0){
        cout << "look at the road!\n";
        return 0;
    }

    string t = s.substr(0, n);
    int cnt=0;
    

    for(int i=n; i<=s.size()-n; i += n){
        string m = s.substr(i, n);
        do{
            if(m == t){ 
                break;
            }
            cnt++;
        }while(next_permutation(m.begin(), m.end()));
    }
    cout << cnt << endl;
    return 0;
}