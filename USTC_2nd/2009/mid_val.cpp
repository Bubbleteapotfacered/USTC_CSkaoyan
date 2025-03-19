#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, num;
    cin >> n;
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    if(n % 2 == 1) cout << nums[n / 2];
    else if(n % 2 == 0) cout << nums[n / 2 - 1] << " " << nums[n / 2];
}