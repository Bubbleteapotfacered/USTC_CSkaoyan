#include<iostream>

#include<vector>

using namespace std;

int main(){
    int num;
    cin >> num;

    vector<char> hex(16,'0');
    for(int i = 0; i < 16; i++){
        if(i <= 9) hex[i] = i + '0';
        else hex[i] = i - 10 + 'A';
        // cout << hex[i];
    }

    vector<char> res;
    while(num > 0){
        res.push_back(hex[num % 16]);
        num /= 16;
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i];
    }


    return 0;



}