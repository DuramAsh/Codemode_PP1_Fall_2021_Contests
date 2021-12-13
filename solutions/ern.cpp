#include <bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    rotate(v.begin(),v.end()-k,v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}