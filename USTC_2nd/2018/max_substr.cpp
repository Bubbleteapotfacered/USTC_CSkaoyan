#include<bits/stdc++.h>

using namespace std;

int max_substr(string& s, string& t){
    // dp[i][j] 的定义为以s[i-1]结尾的s和以t[j-1]结尾的t  最长公共子序列的长度
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1]) {
                // 这次相等  各自前一位加1
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                // 这次不等  取分别删除一位的最大值
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[s.size()][t.size()];
}



int main(){
    ifstream ifs("input4.txt");
    string s, t;
    while(ifs >> s >> t){
        cout << max_substr(s, t) << endl;
    }

    ifs.close();
}