#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int iswanshu(int n){
    if(n < 5) return 3;

    int sum = 1;

    for(int i = 2;  i * i <= n; i++){
        if(n % i == 0 && i * i < n){
            // ����������Ӳ�һ��
            sum += i;
            sum += n / i;
        }else if(n % i == 0 && i * i == n){
            // �����������һģһ��
            // ֻ�ܼ�һ��
            // ����36ֻ�ܼ�һ��6
            sum += i;
        }
    }


    if(sum == n) return 1;
    else if(sum > n) return 2;
    else return 3;
}

int main(){

    for(int i = 2; i <= 1000; i++){
        if(iswanshu(i) == 1) cout << "������" << i << endl;
        if(iswanshu(i) == 2) cout << "ӯ����" << i << endl;
    }


    return 0;

}