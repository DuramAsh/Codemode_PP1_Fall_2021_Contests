#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
int main(){
    stack<int> pizzas;
    queue<pair<bool,int>> q;
    map<int,int> cnt;
    int n,m,time = 0;cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pizzas.push(tmp);
        cnt[tmp]++;
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        q.push(make_pair(false,tmp));
    }
    q.push(make_pair(true,1));
    bool ok = false;
    while(!pizzas.empty()){
        time++;
        if(cnt[1]==0) //1  
            break;// 1T 0 
        if(pizzas.top()==1&&q.front().first){
            ok = true;
            cnt[1]--;
            break;
        }else if(pizzas.top()==q.front().second&&!q.front().first){
            q.pop();
            cnt[pizzas.top()]--;
            pizzas.pop();
        }else{
            pair<bool,int> pr = q.front();
            q.pop();
            q.push(pr);
        }
    }
    if(ok){
        cout<<"YES\n";
        if(time>m)
            cout<<"Che opazdyvaem?\n";
    }else{
        cout<<";(\n";
    }
    return 0;
}