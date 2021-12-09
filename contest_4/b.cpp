#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
        vector<int> temp = nums;
        int n = nums.size();

        // Rotate the elements.
        for (int i = 0; i < n; i++)
        {
            nums[(i + k)%n] = temp[i];
        }
    }

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        nums.push_back(x);
    }

    rotate(nums, k);
    for(auto i: nums){
        cout << i << " ";
    }
    
    return 0;
}