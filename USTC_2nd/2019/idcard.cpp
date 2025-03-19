#include<bits/stdc++.h>

using namespace std;

int prediff[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char last[11] = {'1', '0','X', '9', '8','7','6','5','4','3','2'};
int main(){
    string s;
    cin >> s;
    int sum = 0;
    // 计算累加和
    for(int i = 0; i < 17; i++){
        sum += prediff[i] * (s[i] - '0');
    }
    // 映射
    if(last[sum % 11] == s[17]) cout << "YES";
    else cout << "NO";
}