#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Stoint(string s){
    int sum=0;
    int d = 1;
    for(int i = s.size() - 1; i>= 0; --i){
        sum += int(s[i]-48) * d;
        d *= 10;
    }
    return sum;
}


int main(){
    freopen("input.txt", "r", stdin);
    
    stack<int> st;
    string s;
    getline(cin, s);
    string t = "";
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])){
            t += s[i];
        }
        if(s[i] == ' '){
            int a = Stoint(t);
            st.push(a);
            t = "";
        }
        if(s[i]=='+'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(first+second);
        }else if(s[i]=='-'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second-first);
        }else if(s[i]=='*'){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            st.push(second*first);
        }

    }
    cout << st.top();
    return 0;
}