#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<string> cringe_words;
    while(m--){
        string word;
        cin>>word;
        cringe_words.push_back(word);
    }
    for(int i=0;i<n;i++){
        string congrat;
        int total = 0;
        getline(cin,congrat);
        for(auto word:cringe_words){
            for(int i=0;i<congrat.length()-word.size()+1;i++){
                if(congrat.substr(i,word.size())==word)
                    total += 1000;
            }
        }
        if(total>0){
            cout<<"Emae, balin\n"<<total<<'\n';
        }else{
            cout<<"Kuni eto chetko\n";
        }
    }
    return 0;
}