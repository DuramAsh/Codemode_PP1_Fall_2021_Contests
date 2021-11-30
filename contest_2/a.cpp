#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int longest = 0;

    for(int i=1; i<n-1; i+=2){
        if((arr[i+1] - arr[i]) >= longest){
            longest = arr[i+1]  - arr[i];
        }
    }

    for(int i=1; i<n-1; i+=2){
        if(arr[i+1] - arr[i] == longest){
            cout << arr[i] << " ";
            cout << longest << endl;
        }
    }
    return 0;
}