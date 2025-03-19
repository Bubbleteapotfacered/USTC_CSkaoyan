#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool accept = true;
    // 只能以字母下划线开始
    // 字母数字下划线
    for(int i = 0 ; i < s.size(); i++){
        if(i == 0) {
            // 第一个只能是字母和下划线
            if(!(isalpha(s[i]) || s[i] == '_')){
                accept = false;
                break;
            }
        }else{
            if(!(isalpha(s[i]) || s[i] == '_' || isdigit(s[i]))){
                accept = false;
                break;
            }
        }
    }
    cout << accept;

}