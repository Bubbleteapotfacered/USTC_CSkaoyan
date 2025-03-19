#include<bits/stdc++.h>
using namespace std;

int main(){
    // 矩阵的行和列
    int m, n;
    // cout << "请输入矩阵的行和列：";
    cin >> m >> n;
    
    vector<vector<int>> martix(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> martix[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << martix[j][i] << " ";
        }
        cout << endl;

    }
    return 0;
}