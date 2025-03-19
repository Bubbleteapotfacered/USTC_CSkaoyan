#include<bits/stdc++.h>

using namespace  std;

int main(){
    string s;
    getline(cin, s);
    // s += " ";
    int max_count = 0, count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ') {
            count++;
            // 防止最后一个后面没空格
            // 每次更新都重新计算
            max_count = max(max_count, count);
        }
        else {
            count = 0;
        }
    }
    cout << max_count;
}