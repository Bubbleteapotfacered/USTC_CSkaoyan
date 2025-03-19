#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 0;
    double single = 1;
    for(int i = 1; i <= n; i++){
        single /= i;
        sum += single;
    }
    printf("%.4f", sum);
    
}