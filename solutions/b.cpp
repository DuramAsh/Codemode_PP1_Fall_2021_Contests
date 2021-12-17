#include <iostream>
using namespace std;

void toll(string &s){
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i]+=32;
        }
    }
}

int main(){
    string s;
    string a = "pacify";
    string b = "wine";
    cin>>s;
    toll(s);
    for(int i = 0; i < s.size();i++){
        if(a.empty()) break;
        for(int j = 0 ; j < a.size(); j++){
            if(s[i] == a[j]){
                a.erase(a[j]);
                s.erase(s[i]);
                break;
            }
        }
    } 
    for(int i = 0; i < s.size();i++){
        if(b.empty()) break;
        for(int j = 0 ; j < b.size(); j++){
            if(s[i] == b[j]){
                b.erase(b[j]);
                s.erase(s[i]);
                break;
            }
        }
    } 

    if(a.empty() && b.empty()){
        cout<<"Bubu";
    }
    else{
        cout<<"Wine by";
    }
    return 0;
}