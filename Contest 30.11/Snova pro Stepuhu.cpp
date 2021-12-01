#include <bits\stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int total_credit = 0;
    float gpa_sum = 0;
    for(int i = 0; i < n; i++){
        string course;
        cin >> course;
        string point;
        cin >> point;
        int credit;
        cin >> credit;
        float gpa;
        total_credit += credit;
        if(point == "A"){
            gpa = 4;
        }else if(point == "A-"){
            gpa = 3.67;
        }else if(point == "B+"){
            gpa = 3.33;
        }else if(point == "B"){
            gpa = 3;
        }else if(point == "B-"){
            gpa = 2.67;
        }else if(point == "C+"){
            gpa = 2.33;
        }else if(point == "C"){
            gpa = 2;
        }else if(point == "C-"){
            gpa = 1.67;
        }else if(point == "D+"){
            gpa = 1.33;
        }else if(point == "D"){
            gpa = 1;
        }else if(point == "D-"){
            gpa = 0.67;
        }else if(point == "F"){
            gpa = 0;
        }
        gpa_sum += gpa * credit;
    }
    cout << gpa_sum/total_credit << endl;
    if((gpa_sum/total_credit) >= 1.65){
        cout << "Shikuem";
    }else{
        cout << "Alo, mama?";
    }
}