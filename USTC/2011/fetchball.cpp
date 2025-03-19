#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
vector<int> path;
int result = 0;

int pre = -1;


void backtracking(int startindex, vector<int>& balls){
    // 组合问题
    if(path.size() == 8){
        res.push_back(path);
        result++;
        return ;
    }
    // 树层剪枝---去重
    for(int i = startindex; i < balls.size(); i++){
        if(pre == balls[i]) continue;
        path.push_back(balls[i]);
        backtracking(i + 1, balls);
        path.pop_back();
        pre = balls[i];
    }


}

int main(){
    int x, y, k;
    cin >> x >> y >> k;

    // 用数字来表示
    // 1 为红球，2为黄球，3为黑球
    vector<int> balls(12,0);
    for(int i = 0; i < 12; i++){
        if(i < x) balls[i] = 1;
        else if(i < x + y) balls[i] = 2;
        else balls[i] = 3;
    }
    backtracking(0, balls);

    cout << result << "种取法" << endl;
    for(int i = 0; i < res.size(); i++){
        int red = 0, yellow = 0, black = 0;
        for(int j = 0; j < res[i].size(); j++){
            if(res[i][j] == 1) red++;
            else if(res[i][j] == 2) yellow ++;
            else black++;
        }
        cout << i + 1 << ":" << red << "个红球  " << yellow << "个黄球  " << black << "个黑球";
        cout << endl;
    }

}