#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int iswanshu(int n){
    if(n < 5) return 3;

    int sum = 1;

    for(int i = 2;  i * i <= n; i++){
        if(n % i == 0 && i * i < n){
            // 如果两个因子不一样
            sum += i;
            sum += n / i;
        }else if(n % i == 0 && i * i == n){
            // 如果两个因子一模一样
            // 只能加一次
            // 比如36只能加一次6
            sum += i;
        }
    }


    if(sum == n) return 1;
    else if(sum > n) return 2;
    else return 3;
}

int main(){

    for(int i = 2; i <= 1000; i++){
        if(iswanshu(i) == 1) cout << "完数：" << i << endl;
        if(iswanshu(i) == 2) cout << "盈数：" << i << endl;
    }


    return 0;

}