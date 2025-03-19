#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    int s;
    // 两个矩阵的大小
    cin >> m >> n;
    cin >> n >> s;

    vector<vector<int>> mar_1(m, vector<int>(n, 0));

    vector<vector<int>> mar_2(n, vector<int>(s, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mar_1[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < s; j++)
        {
            cin >> mar_2[i][j];
        }
    }

    vector<vector<int>> res(m ,vector<int>(s, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < s; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += mar_1[i][k] * mar_2[k][j];
            }
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    

}