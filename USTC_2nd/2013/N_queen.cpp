#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> res;

bool canbeplaced(vector<string>& path, int x, int y){
    // 同一列
    for(int i = 0; i < x; i++){
        if(path[i][y] == 'Q') return false;
    }
    // 左上角
    for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
        if(path[i][j] == 'Q') return false;
    }
    // 右上角
    for(int i = x - 1, j = y + 1; i >= 0 && j < path.size(); i--, j++){
        if(path[i][j] == 'Q') return false;
    }
    return true;
}
// path为当前的那个
void backtracking(vector<string>& path, int curx){
    // 到第n + 1行  收集结果
    if(curx == path.size()){
        res.push_back(path);
        return ;
    }
    for(int j = 0; j < path[curx].size(); j++){
        if(canbeplaced(path, curx, j)){
            path[curx][j] = 'Q';
            // 下一行
            backtracking(path, curx + 1);
            path[curx][j] = '.';
        }
    }
}


int main(){
    ifstream ifs("5.in");
    ofstream ofs("5.out");

    int n;
    ifs >> n;
    vector<string> path(n, string(n, '.'));
    backtracking(path, 0);

    ofs << res.size() << endl << endl;
    for(vector<string> path : res){
        for(string s : path) ofs << s << endl;
        ofs << endl;
    }

    ifs.close();
    ofs.close();

}