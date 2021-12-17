#include <iostream>
#include <vector>

using namespace std;

vector<string> string_to_vec(string s){
    vector<string> v;
    int p = 0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ' '){
            p = i;
        }else if(s[i] == ' ' || i == s.size()){
            v.push_back(s.substr(p, i-p));
            p = i + 1;
        }
    }
    return v;
}

int main(){
    string s;
    getline(cin, s);
    vector<string> v = string_to_vec(s);
    for(auto i: v){
        cout << i << endl;
    }
        
    
    return 0;
}

