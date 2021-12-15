#include <bits/stdc++.h>
using namespace std;
int main(){
    string str, res;
    cin >> str;
    int k = 0;
    int pos = str.find('1');
    while(pos + 1){
        k = 0;
        for(int i = pos - 1; i >= 0; --i){
            if(str[i] == '0')
                k++;
            else
                break;
        }
        res.push_back(97 + k);
        pos = str.find('1',pos + 1);
    }
    cout << res;
    return 0;
}