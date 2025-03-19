#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("number.in");
    ofstream ofs("number.out");
    vector<int> nums;
    int num;
    while(ifs >> num){
        nums.push_back(num);
    }
    // dp[i]的定义为  以nums[i]结尾的连续子数组的最大和
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max_val = INT_MIN;
    for(int i = 1; i < nums.size(); i++){
        // 两种情况
        // 1.连着前面
        // 2.自己一个
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        max_val = max(max_val, dp[i]);
    }

    ofs << max_val;

    ifs.close();
    ofs.close();
}