#include<bits/stdc++.h>
using namespace std;
bool isValid(string& s){

    // 先判断首字符只能为A-Z, a-z, _
    if(! ( (s[0] <= 'z' && s[0]>= 'a') || (s[0] <= 'Z' && s[0] >= 'A') || s[0] == '_')  ){
        return false;
    }
    for(int i = 1; i < s.size(); i++){
        if(!( (s[i] <= 'z' && s[i]>= 'a') || (s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= '9' && s[i] >= '0') || s[i] == '_')){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}