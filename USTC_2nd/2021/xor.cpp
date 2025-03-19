#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    // 相当于各自的二进制进行异或
    int res = a ^ b;
    int count = 0;
    while(res > 0){
        // 求二进制中1个个数即可
        count += res % 2;
        res /= 2;
    }
    cout << count;
}