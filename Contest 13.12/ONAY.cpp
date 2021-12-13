#include<bits/stdc++.h>
#define P(xx,yy) make_pair(min(xx,yy),max(xx,yy))
using namespace std;

int q[400];
int n,x,y,k,f;

bool cmp(int aa,int bb){
    return aa>bb;
}

int main()
{   cin>>n>>x>>y>>k>>f;
    map<string,int> pp;
    map<pair<int,int>,int> p;

    string a,b;
    int ans=0,coo=0,cnt=0,temp=-1;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(!pp[a]) pp[a]=++cnt;         
        if(!pp[b]) pp[b]=++cnt;
        coo=(pp[a]==temp?y:x);           
        p[P(pp[a],pp[b])]+=coo;          


        ans=ans+coo;                     
        temp=pp[b];
    }

    cnt=0;
    for(auto i=p.begin();i!=p.end();i++) q[cnt++]=i->second;

    sort(q,q+cnt,cmp);
    for(int i=0;i<k;i++){
        if(q[i]<f) break;
        else ans-=q[i]-f;                
    }
    cout<<ans<<endl;
}