#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double k = 1;
    double sum = 0;
    // 累加
    for(int i = 1; i <= n; i++){
        k /= i;
        sum += k;
    }
    printf("%.4f", sum);
}