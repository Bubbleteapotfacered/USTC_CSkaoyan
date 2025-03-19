#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input3.txt");
    vector<int> nums;
    int num;
    while(ifs >> num){
        nums.push_back(num);
    }
    
    map<int, vector<int>> dp;

    int max_val = 0;
    // dp[diff][i] 的含义是以diff为公差, nums[i]为结尾, 的最长等差子序列的长度
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i] - nums[j];
            if(dp.find(diff) == dp.end()){
                // 这个公差还没构建
                // 本身就是1，初始化为1
                dp[diff] = vector<int>(nums.size(), 1);
            }
            // 递推公式
            // 如果在前面找到了差为diff的，那么长度加1
            dp[diff][i] = dp[diff][j] + 1;
            max_val = max(max_val, dp[diff][i]);
        }
    }
    cout << max_val;

    ifs.close();
}