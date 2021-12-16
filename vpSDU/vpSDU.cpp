#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<string,int>>students;
    for(int i=0;i<n;i++){
        string name;
        int points;
        cin>>name>>points;
        students.push_back(make_pair(name,points));
    }
    vector<pair<string,int>>real_marks;
    for(int i=0;i<n;i++){
        real_marks.push_back(students[i]);
        if(students[i].second<30){
            if(i+k<n)
                real_marks[i].second = students[i + k].second;
            else
                real_marks[i].second = students[n - i - k + 1].second;
        }
    }
    bool retake = false;
    for(int i=0;i<n;i++){
        if(real_marks[i].second<30){
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