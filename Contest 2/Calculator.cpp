#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        char oper; cin >> oper;
        float f, s; cin >> f >> s;
        if(oper == '+'){
            cout << f << " + " << s << " = " << f + s << endl;
        }else if(oper == '-'){
            cout << f << " - " << s << " = " << f - s << endl;
        }else if(oper == '*'){
            cout << f << " * " << s << " = " << f * s << endl;
        }else if(oper == '/'){
            if(s != 0){
                cout << f << " / " << s << " = " << f / s << endl;
            }else{
                cout << "Ne chetko" << endl;
            }
        }
    }
}