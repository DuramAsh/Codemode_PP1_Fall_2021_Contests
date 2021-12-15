#include <bits\stdc++.h>
#define l unsigned long long
//mozhno "long long" po idee
using namespace std;

bool isPerfectSquare(l x){
    l s = sqrt(x);
    return (s*s == x);
}
 
bool isFibonacci(l n){
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}
 
int main(){
    l n; cin >> n;
    if(isFibonacci(n)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}