#include <iostream>
#include <set>
using namespace std;

void set_print(set<int> & s){
    set<int> :: iterator it;
    for(it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void set_erase(set<int> & s, int x){
    set<int> :: iterator it;
    for(it = s.begin(); it != s.end(); it++){
        if(*it == x){
            s.erase(it);
            cout << "Deleted" << endl;
            return;
        }
    }
    cout << "Doesn't exist" << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    int n; cin >> n;
    while(n--){
        set<int> s;
        int k; cin >> k;
        while(k--){
            string command;
            cin >> command;
            if(command == "Insert"){
                int x; cin >> x;
                s.insert(x);
            }else if(command == "Print"){
                set_print(s);
            }else if(command == "Delete"){
                int x; cin >> x;
                set_erase(s,x);
            }
        }
        cout << endl;
    }
}