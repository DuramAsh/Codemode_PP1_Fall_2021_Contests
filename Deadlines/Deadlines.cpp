#include<bits/stdc++.h>
using namespace std;

map<string,int> day_ind;
    
bool cmp(pair<string,pair<string,int>> p1, pair<string,pair<string,int>> p2){
    if(p2.second.first!=p1.second.first)
        return day_ind[p2.second.first] > day_ind[p1.second.first];
    else if(p2.second.first==p1.second.first && p2.second.second!=p1.second.second)
        return  p2.second.second < p1.second.second;
    else if(p2.second.first==p1.second.first && p2.second.second==p1.second.second)
        return p2.first < p1.first;
}

int main(){
    
    day_ind["Monday"] = 1;
    day_ind["Tuesday"] = 2;
    day_ind["Wednesday"] = 3;
    day_ind["Thursday"] = 4;
    day_ind["Friday"] = 5;
    day_ind["Saturday"] = 6;

    int n; cin>>n;
    vector<pair<string,pair<string,int>>> tasks;
    for(int i=0;i<n;i++){
        string sub,day;
        int complexity;
        cin>>sub>>day>>complexity;
        tasks.push_back(make_pair(sub,make_pair(day,complexity)));
    }
    sort(tasks.begin(),tasks.end(),cmp);

    queue<pair<string,pair<string,int>>> q;
    vector<string> left;
    int cur_day = 0;

    for(auto task:tasks){
        q.push(task);
        cout<<task.first<<" "<<task.second.first<<" "<<task.second.second<<endl;
    }
    
    while(!q.empty()&&cur_day<6){
        int total_complexity = 0;
        if(cur_day>=day_ind[q.front().second.first]){
            left.push_back(q.front().first);
            q.pop();
        }
        if(q.empty())
            break;
        while(!q.empty()&&total_complexity+q.front().second.second<=10){
            total_complexity += q.front().second.second;
            q.pop();
        }
        cur_day++;
    }
    if(left.empty())
        cout<<"YES\n";
    else{
        cout<<"NO\n";
        for(auto t:left)
            cout<<t<<endl;
    }
    return 0;
}