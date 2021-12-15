#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2){
    if (s1 == s2) { return true; }
    // Find the first difference in s1
    auto iter = mismatch(begin(s1), end(s1), cbegin(s2)).first;
        
    // Find the last difference in s1
    auto rter = mismatch(rbegin(s1), rend(s1), crbegin(s2)).first;
        
    // Swap the two characters
    swap(*iter, *rter);   
    return s1 == s2;
}

bool check_2(string s1, string s2){
    vector<int> x; 
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            x.push_back(i);
        }
    }
    if(x.size()==0)
        return true;
    if(x.size()==2){
        swap(s1[x[0]],s1[x[1]]);
    }
    return s1==s2; 
}

bool check_3(string s1, string s2) {
    vector<int> diff; 
    for (int i = 0; i < s1.size(); ++i) 
        if (s1[i] != s2[i]) diff.push_back(i); 
    return diff.size() == 0 || (diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]); 
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(check(s1, s2)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}