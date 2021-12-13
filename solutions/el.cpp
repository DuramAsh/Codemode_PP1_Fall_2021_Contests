#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char arr[10][10];

bool res(int x, int y, int a, int b){
    if(arr[x][y]=='*'){
        return false;
    }else if(x==a && y==b){
        return true;
    }

    if(arr[x-1][y]=='.' && x>=0 && y>=0 && x<10 && y<10){
        return res(x-1, y, a, b);
    }else if(arr[x+1][y]=='.' && x>=0 && y>=0 && x<10 && y<10){
        return res(x+1, y,a , b);
    }else if(arr[x][y-1]=='.' && x>=0 && y>=0 && x<10 && y<10){
        return res(x,y-1, a, b);
    }else if(arr[x][y+1]=='.' && x>=0 && y>=0 && x<10 && y<10){
        return res(x, y+1, a, b);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // char arr[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>arr[i][j];
        }
    }
    int a, b , c, d;
    cin>>a>>b>>c>>d;

    if(res(a, b, c, d)){
        cout<<"Found))";
    }else if(!res(a, b, c, d)){
        cout<<"Not found((";
    }

    
    return 0;
}