#include <iostream>
#include <stack>
using namespace std;
int main(){
    // freopen("input_stack.txt", "r", stdin);
    string s; cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(not st.empty()){
                if((s[i] == ')' and st.top() == '(') or 
                (s[i] == ']' and st.top() == '[') or 
                (s[i] == '}' and st.top() == '{')){
                    st.pop();
                }
                else{
                    cout << "No" << endl;
                    return 0;
                }
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << ((st.empty()) ?  "Yes" : "No");
}