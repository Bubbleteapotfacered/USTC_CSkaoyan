#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    if(n % 2 == 1) cout << nums[ n / 2] << endl;
    else cout << nums[n / 2 - 1] << " " << nums[n / 2] << endl;


    return 0;

}