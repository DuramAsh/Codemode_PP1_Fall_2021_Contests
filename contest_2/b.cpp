#include <iostream>

using namespace std;

string Mirror(string s){
    for(int i=s.size()-1; i>= 0; --i){
        if(s[i] == '('){
            s += ')';
        }else{
            s += s[i];
        }
    }
    return s;
}

string recMirror(string s, int i){
    if(s[i] == '('){
        s += ')';
    }else{
        s += s[i];
    }
    if(i == 0){
        return s;
    }
    return recMirror(s, i-1);

}

int main(){
    string s;
    cin >> s;
    // cout << Mirror(s) << endl;
    cout << recMirror(s, s.size()-1);
    return 0;
}