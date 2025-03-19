#include<bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;

    cin >> s1 >> s2;

    // dp[i][j]的定义为以s1[i-1]结尾的s1和以s2[j-1]结尾的s2的  的最小步长

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

    // 初始化
    for(int i = 1; i <= s1.size(); i++) dp[i][0] = i;
    for(int j = 1; j <= s2.size(); j++) dp[0][j] = j;

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                // 增删
                dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1);
                // 改
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    cout << dp[s1.size()][s2.size()];
}