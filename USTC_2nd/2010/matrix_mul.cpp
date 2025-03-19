#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    int s;
    cin >> m >> n;
    cin >> n >> s;
    vector<vector<int>> m1(m, vector<int>(n, 0));
    vector<vector<int>> m2(n, vector<int>(s, 0));

    int ele;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> ele;
            m1[i][j] = ele;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cin >> ele;
            m2[i][j] = ele;
        }
    }
    vector<vector<int>> res(m, vector<int>(s, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < s; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < s; j++){
            
            cout <<  res[i][j] << " ";
            
        }
        cout << endl;
    }
    
}