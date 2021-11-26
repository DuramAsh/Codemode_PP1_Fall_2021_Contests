#include <bits/stdc++.h>

using namespace std;

int bonusPoints(vector<char> v) {
    stack<int> s;
    for(int i=0; i<v.size(); i++){
        if(isdigit(v[i])){
            s.push(int(v[i]-48));
        }
        if(v[i] == 'C'){
            s.pop();
        }
        if(v[i] == 'D'){
            s.push(s.top() * 2);
        }
        if(v[i] == '+'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.push(a);
            s.push(a + b);
            
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    return sum;
            
}


int main(){
    int n;
    cin >> n;
    vector<char> v;
    char c;

    for(int i=0; i<n; i++){
        cin >> c;
        v.push_back(c);    
    }
    cout << bonusPoints(v);
    return 0;
}