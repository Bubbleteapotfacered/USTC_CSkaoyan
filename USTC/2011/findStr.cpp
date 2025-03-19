#include<bits/stdc++.h>

using namespace std;


// 在文件3.txt中查看是否有模式 abcde。若有，输出找到abc*d?e匹配；若无，则输出没有找到abc*d?e匹配，将结果输出到控制台。
// *表示0次或者多次
// +表示至少一次
// ？表示0次或1次

bool check(string& s, int start){
    // 判断a
    if(start >= s.size() || s[start++] != 'a') return false;
    // 判断b
    if(start >= s.size() || s[start++] != 'b') return false;
    // 判断c*  零个或者多个c
    while(start < s.size() && s[start] == 'c') start++;
    // 判断d?  count 为次数
    int count = 0;
    // 统计d的个数
    if(start < s.size() && s[start] == 'd'){
        count++;
        start++;
    }
    // 大于等于两次直接不匹配
    if(count >= 2) return false;
    
    if(start >= s.size() || s[start] != 'e') return false;
    return true;
}

int main(){

    ifstream ifs("3.txt");
    string s;
    ifs >> s;
    // cout << s;
    for(int i = 0; i < s.size(); i++){
        if(check(s, i)) {
            cout << "Find 'abc*d?e' Match" << endl;
            return 0;
        }
    }
    cout << "Not Find 'abc*d?e' Match" << endl;
    return 0;
    ifs.close();
    return 0;
}