#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string a[n];
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);
        a[i] = s;
    }
    for(int i=0; i<n; i++){
        cout << a[i] << "\n";
    }
    return 0;
}