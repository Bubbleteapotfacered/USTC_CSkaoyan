#include<bits/stdc++.h>

using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    int res = num1 ^ num2;
    vector<int> bin;
    while(res > 0){
        bin.push_back(res % 2);
        res /= 2;
    }
    for(int i = bin.size() - 1; i >= 0; i--){
        cout << bin[i];
    }
}