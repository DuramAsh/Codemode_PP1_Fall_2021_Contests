#include<iostream>
#include<stack>
#include<string>
using namespace std;

int Stoi(string s){
    int sum=0;
    int d = 1;
    for(size_t i = s.size() - 1; i>= 0; --i){
        sum += int(s[i]-48) * d;
        d *= 10;
    }
    return sum;
}

int main(){
    freopen("input.txt", "r", stdin);
    
    stack<int> st;
    string s;
    string t="";
    getline(cin,s);

    for(int i=0;i<s.size();i++){
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
        }else if(s[i]!=' '){
            t+=s[i];
        }else if(s[i]==' '){
            int res = Stoi(t);
            cout << res << endl;
            st.push(res);
            t="";
        }
    }
    cout<<st.size()<<endl;
    return 0;

}