#include<bits/stdc++.h>

using namespace std;

int max_list(string& s, string& t){
    // dp[i][j]的含义为以s[i-1]结尾字符串和以t[j-1]结尾的字符串的最长公共子序列的长度
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    // dp[0][j]和dp[i][0]全部初始化为0
    int max_val = 0;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]){
                // 在原来的基础上加1
                dp[i][j] = dp[i- 1][j - 1] + 1;
            }else{
                // 保持原来的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            max_val = max(max_val, dp[i][j]);
        }
    }
    return max_val;
}


int main(){
    ifstream ifs("input4.txt");
    string s, t;
    while(ifs >> s >> t){
        cout << max_list(s, t) << endl;
    }
    ifs.close();
}
