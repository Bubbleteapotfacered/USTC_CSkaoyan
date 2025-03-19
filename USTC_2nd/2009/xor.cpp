#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> bin(16,0);
    for(int i = 0; i < 16; i++){
        bin[i] = num % 2;
        num /= 2;
    }
    vector<int> res(4, 0);
    for(int i = 0; i < 4; i++){
        res[i] = bin[i * 4 + 0] ^ bin[i * 4 + 1] ^ bin[i * 4 + 2] ^ bin[i * 4 + 3];
    }
    int sum = 0;
    for(int i = 0; i < 4; i++){
        if(res[i] == 1) sum += pow(2, i);
    }
    cout << sum;
}