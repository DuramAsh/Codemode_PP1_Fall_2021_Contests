#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> cringe_words;
    while(n--){
        string tmp;
        cin>>tmp;
        cringe_words.push_back(tmp);
    }
    int total = 0;
    while(m--){
        string to_check;
        cin>>to_check;
        for(auto word:cringe_words)
            if(to_check.substr(0,word.size())==word)
                total += 1000;
    }
    if(total>0)
        cout<<"Emae, Balin\n"<<total<<'\n';
    else
        cout<<"Kuni eto chetko\n";
    return 0;
}