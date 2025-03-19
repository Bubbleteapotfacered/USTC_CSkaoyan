#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int pwd = 0;
    int alpha = 0;
    int digit = 0;
    int others = 0;
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) alpha++;
        else if(isdigit(s[i])) digit++;
        else if(s[i] == ' ') pwd++;
        else others++;
    }
    printf("alpha %d\ndigit %d\npwd %d \nothers %d \n", alpha, digit, pwd, others);
}