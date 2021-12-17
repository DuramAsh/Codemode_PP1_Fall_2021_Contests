#include<iostream>
#include<cmath>
using namespace std;
bool has_square(int n){
    float sq = sqrt(n);
    if(floor(sq) == ceil(sq))
        return true;
    return false;
}
bool can(int n){
    if(n==1)
        return true;
    if(n<=0)
        return false;
    if(n%2!=0&&n%3!=0&&!has_square(n))
        return false;
    if(has_square(n)&&n%2==0&&n%3==0)
        return can(n/2)||can(n/3)||can(ceil(sqrt(n)));
    else if(has_square(n)&&n%2==0&&n%3!=0)
        return can(n/2)||can(ceil(sqrt(n)));
    else if(has_square(n)&&n%2!=0&&n%3==0)
        return can(n/3)||can(ceil(sqrt(n)));
    else if(!has_square(n)&&n%2==0&&n%3==0)
        return can(n/2)||can(n/3);
    else if(!has_square(n)&&n%2!=0&&n%3==0)
        return can(n/3);
    else if(!has_square(n)&&n%2==0&&n%3!=0)
        return can(n/2);
}
int main(){
    int n;cin>>n;
    if(can(n))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}