#include<bits/stdc++.h>
using namespace std;

bool ishuiwen(string s){
    int i = 0, j = s.size() - 1;
    for(; i < j; i++, j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(ishuiwen(s)){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
    return 0;
}