#include<bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    // dp[i][j]表示以下标i-1为结尾的s 转为  以下标j-1为结尾的j  的最小操作数
    // 共有三种操作    插入删除修改

    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    // 初始化  从i长度转为0长度，需要i次删除
    for(int i = 1; i <= s.size(); i++) dp[i][0] = i;
    // 初始化  从j长度转为0长度  需要j次删除
    for(int j = 1; j <= t.size(); j++) dp[0][j] = j;
    
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            // 如果相等，和前面一样
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                // 如果不相等   删除   或者  修改
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    cout << dp[s.size()][t.size()];
}