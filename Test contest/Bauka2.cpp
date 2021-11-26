#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<string,int>priority;
bool cmp(string s1,string s2){
    return priority[s1]>priority[s2];
}
int main(){
    int n,m;
    cin>>n>>m;
    string nums[m];
    for(int i=0;i<m;i++)
        cin>>nums[i];
    set<string> numbers;
    for(int i=0;i<m;i++){
        numbers.insert(nums[i]);
        for(auto c:nums[i])
            if(c=='7'||c=='J')
                priority[nums[i]]++;
    }
    vector<string>numbers_v;
    for(auto it:numbers)
        numbers_v.push_back(it);
    sort(numbers_v.begin(),numbers_v.end(),cmp);
    if(numbers_v.size()<n)
        cout<<"Jaqs is mad\n";
    else{
        cout<<"Jaqs likes it\n";
        for(int i=0;i<n;i++)
            cout<<numbers_v[i]<<" ";
    }
    return 0;
}