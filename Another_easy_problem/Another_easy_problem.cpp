#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<char>res;
    for(int i=0;i<n;i++){
        string tmp;cin>>tmp;
        for(int i=0;i<tmp.length();i++)
            tmp[i] = tolower(tmp[i]);
        if(i==0){
            for(int j=0;j<tmp.length();j++)
                res.insert(tolower(tmp[j]));
        }else{
            vector<char>to_erase;
            for(char chr:res){
                if(tmp.find(chr)==string::npos)
                    to_erase.push_back(chr);
            }
            for(auto chr:to_erase)
                res.erase(chr);
        }
    }
    if(res.size()==0)
        cout<<"NO COMMON CHARACTERS\n";
    else
        for(auto chr:res)
            cout<<chr<<" ";
    return 0;
}