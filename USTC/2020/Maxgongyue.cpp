#include<bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int res = 0;
    for(int i = 1; i <= min(m, n); i++){
        if(m % i == 0 & n % i == 0){
            res = i;
        }
    }
    cout << res;


}