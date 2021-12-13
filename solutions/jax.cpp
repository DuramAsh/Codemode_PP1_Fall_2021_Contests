#include <iostream>

using namespace std;


int Jax(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    } 
    return (Jax(n-1) + Jax(n-2)) % 10;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << Jax(i) << " ";
    }
    return 0;
}