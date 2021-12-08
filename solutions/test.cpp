#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    string a = "pacify";
    // string b = "wine";
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(s[i] == a[j]){
                s.erase(i, 1);
                a.erase(j, 1);
                i--;
                j--;
            }
        }
    }
    cout << s << endl << a;
    return 0;
}