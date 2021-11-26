#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    map<string, vector<string> > mm;
    map<string, vector<string> > :: iterator it;
    while(n--){
        string cn;
        cin >> cn;
        int k;
        cin >> k;
        vector<string> v;
        for(int i=0; i<k; i++){
            string ct;
            cin >> ct;
            v.push_back(ct);
        }
        mm[cn] = v;
    }
    int m;
    cin >> m;
    bool founded = false;
    while(m--){
        string s;
        cin >> s;
        for(it = mm.begin(); it != mm.end(); it++){
            vector<string> v((*it).second.begin(), (*it).second.end());
            if(find(v.begin(), v.end(), s) != v.end()){
                cout << (*it).first << endl;
                founded = true;
                break;
            }
        }
        if(!founded){
            cout << "Ondai joq\n";
        }
        founded = false;
    }
    return 0;
}