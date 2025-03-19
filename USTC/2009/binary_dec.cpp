#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> bin(16,0);
    // 十进制转换为二进制
    for(int i = 15; i >= 0; i--){
        if(n % 2 == 1) bin[i] = 1;
        else bin[i] = 0;
        n /= 2;
    }
    vector<int> res(4,0);
    int sum = 0;
    for(int i = 0; i < 4; i++){
        int temp = bin[i * 4] ^ bin[i * 4 + 1] ^ bin[i * 4 + 2] ^ bin[i * 4 + 3];
        res[i] = temp;
        sum = sum * 2 + res[i];
    }

    cout << sum;
    
}
