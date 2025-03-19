#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    vector<int> oct;
    while(num > 0){
        oct.push_back(num % 8);
        num /= 8;
    }
    for(int i = oct.size() - 1; i >= 0; i--){
        cout << oct[i];
    }
}