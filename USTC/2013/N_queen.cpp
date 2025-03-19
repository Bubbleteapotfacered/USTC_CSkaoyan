#include<bits/stdc++.h>
using namespace std;

bool isOK(int x, int y, vector<vector<char>>& path){
    // 同一列
    for(int i = 0; i < x; i++){
        if(path[i][y] == 'Q') return false;
    }
    // 左上角
    for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--,j--){
        if(path[i][j] == 'Q') return false;
    }
    // 右上角
    for(int i = x - 1, j = y + 1; i >= 0 && y < path.size(); i--, j++){
        if(path[i][j] == 'Q') return false;
    }
    // 可以放置
    return true;
}

int res = 0;

void backtracking(int n, int cur, vector<vector<char>>& path){
    // 终止条件
    // 到下一行
    if(cur == n){
        res++;
        return ;
    }
    for(int j = 0; j < n; j++){
        // 符合位置
        // 以cur表示行
        if(isOK(cur, j, path)){
            // 设为Q
            path[cur][j] = 'Q';
            backtracking(n, cur + 1, path);
            // 回溯
            path[cur][j] = '.';
        }
    }
}


int main(){
    ifstream ifs("5.in");
    ofstream ofs("5.out");
    int n;
    ifs >> n;
    vector<vector<char>> path(n, vector<char>(n,'.'));

    backtracking(n, 0, path);
    cout << res;
    ofs << res;
    
    ifs.close();
    ofs.close();
}