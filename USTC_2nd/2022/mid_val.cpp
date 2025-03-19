#include<bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> A(m, 0);
    vector<int> B(n, 0);
    for(int i = 1; i <= m; i++){
        cin >> A[i - 1];
    }
    for(int i = 1; i <= n; i++){
        cin >> B[i - 1];
    }
    vector<int> res;

    int ai = 0, bi = 0;
    while(ai < m || bi < n){
        if(ai < m && bi < n){
            if(A[ai] < B[bi]){
                res.push_back(A[ai++]);
            }else{
                res.push_back(B[bi++]);
            }
        }else if(ai == m){
            res.push_back(B[bi++]);
        }else{
            res.push_back(A[ai++]);
        }
    }
    if((m+n) % 2 == 1){
        cout << res[(m + n) / 2];
    }else{
        cout << res[(m + n) / 2 - 1] << " " << res[(m + n) / 2];
    }
}