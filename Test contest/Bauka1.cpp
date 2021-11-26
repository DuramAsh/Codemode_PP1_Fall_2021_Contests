#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    string name;
    float points;
    queue<pair<string,float>> qu;
    int t,n;
    cin>>t>>n;
    for (size_t i = 0; i < t; i++){
        cin>>name>>points;
        qu.push(make_pair(name,points));
    }
    vector<string> ans;
    while(ans.size()<n){
        pair<string,float> student = qu.front();
        qu.pop();
        if(student.second>qu.front().second)
            ans.push_back(student.first);
        else
            qu.push(student);
    }
    for(auto it:ans)
        cout<<it<<"\n";
    return 0;
}