#include<bits/stdc++.h>

using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    x *= 100;
    int count = 0;
    while(count < n - 1){
        double val = rand() % x;
        // 不够 
        if(x - val < (n - count) * 1){
            continue;
        }else{
            x -= val;
            cout << val / 100 << " ";
            count++;
        }
    }
    cout << x * 1.0 / 100;
}