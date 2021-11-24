#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

int Average(vector<int> v){
    return (v[0] + v[1] + v[2]) / 3;
}

void Darker(vector<int> &v, int avg){
    for(int i=0; i<v.size(); i++){
        if(v[i] + avg > 255){
            v[i] = 255;
        }else{
            v[i] += avg;
        }
    }
}

void Lighter(vector<int> &v, int avg){
    for(int i=0; i<v.size(); i++){
        if(v[i] - avg < 0){
            v[i] = 0;
        }else{
            v[i] -= avg;
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;
    map<string, vector<int> > m;
    string s;
    int x;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int i=0; i<3; i++){
            cin >> x;
            m[s].push_back(x);
        }
    }

    map<string, vector<int> > :: iterator it;
    for(it = m.begin(); it != m.end(); it++){
        int avg = Average((*it).second);
        if((*it).first.size() % 2 == 0){
            Darker((*it).second, avg);
        }else{
            Lighter((*it).second, avg);
        }
    }

    for(it = m.begin(); it != m.end(); it++){
        cout << (*it).first << ": ";
        for(int i = 0; i < (*it).second.size(); i++){
            cout << (*it).second[i] << " ";
        }
        cout << endl;
    
    }
    

    return 0;
}