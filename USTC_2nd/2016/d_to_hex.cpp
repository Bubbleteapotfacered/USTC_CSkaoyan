#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<char> hex;
    for(int i = 0; i < 16; i++){
        if(i < 10) hex.push_back(i + '0');
        else hex.push_back(i + 'a' - 10);
    }
    vector<char> res;
    int num;
    cin >> num;
    while(num > 0){
        res.push_back(hex[num % 16]);
        num /= 16;
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i];
    }
}