#include<bits/stdc++.h>
using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int index = 0;
    // 遍历
    for(int i = 1; i <= min(num1, num2); i++){
        if(num1 % i == 0 && num2 % i == 0) index = i;
    }
    cout << index;
}