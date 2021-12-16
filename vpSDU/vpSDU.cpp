#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<pair<string,int>>students;
    for(int i=0;i<n;i++){
        string name;
        int points;
        cin>>name>>points;
        students.push_back(make_pair(name,points));
    }
    for(int i=0;i<n;i++){
        if(students[i].second<30){
            if(i-k>=0)
                students[i].second = students[i - k].second;
            else{
                int tmp_k = i - k;
                students[i].second = students[n - tmp_k].second;
            }
        }
    }
    bool retake = false;
    for(int i=0;i<n;i++){
        if(students[i].second<30){
            retake = true;
            break;
        }
    }
    if(retake)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}