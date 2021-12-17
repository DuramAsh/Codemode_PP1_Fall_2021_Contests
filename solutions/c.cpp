// Yaslan
#include<bits/stdc++.h>
using namespace std;

string tolower(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>64 && s[i]<91){
            s[i]=s[i]+32;
        }
    }
    return s;
}

bool mysort(pair<string,double> &a, pair<string,double> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }    
    else{
        return a.second>b.second;
    }    
}
int main(){
    freopen("input.txt", "r", stdin);
    map<string,double> m;
    map<string,double> :: iterator it;
    string s;
    while(cin>>s){
        s=tolower(s);
        m[s]++;
    }

    int sum=0;
    for(it=m.begin();it!=m.end();it++){
        sum+=(*it).second;
    }

    for(it=m.begin();it!=m.end();it++){
        (*it).second=((*it).second/sum)*100;
    }
    vector<pair<string, double> > v(m.begin(), m.end());
    sort(v.begin(),v.end(),mysort);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " : " << v[i].second << "%\n";
    }
    return 0;
}