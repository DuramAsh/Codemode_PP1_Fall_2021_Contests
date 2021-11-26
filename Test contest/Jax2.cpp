#include <bits/stdc++.h>
using namespace std;
const int days = 14;
int main(){
    freopen("inputJ2.txt", "r", stdin);
    queue<string> cars, desire;
    int n, m;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s;
        cars.push(s);
    }
    cin >> m;
    for (int i = 0; i < m; ++i){
        cin >> s;
        desire.push(s);
    }
    int cnt = 0;
    while(!desire.empty()){
        if (cnt == days){
            cout << "Shara is crying((";
            return 0;
        }
        if (cars.front() == desire.front()){
            cars.pop();
            desire.pop();
        } else {
            cars.push(cars.front());
            cars.pop();
        }
        cnt++;
    }
    printf("Shara has nourished his desires in: %d days", cnt);

    return 0;
}