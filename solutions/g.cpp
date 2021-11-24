#include <iostream>
#include <stack>

using namespace std;

int main(){
    string t;
    cin >> t;
    stack<char> s;
    for(int i=0; i<t.size(); i++){
        if(t[i] == '0' || s.empty()){
            s.push(t[i]);
        }else{
            if(s.top() == '0'){
                s.push(t[i]);
            }else{
                s.pop();
            }
        }
    }
    string l = "";
    while(!s.empty()){
        l = s.top() + l;
        s.pop();
    }
    cout << l;
    return 0;
}