#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;

    getline(cin, s);
    int alpha = 0;
    int digit = 0;
    int pwd = 0;
    int other = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i])){
            alpha++;
        }else if(isdigit(s[i])){
            digit++;
        }else if(s[i] == ' '){
            pwd++;
        }else other++;
    }
    cout << alpha << "????? " << digit << "?????? " << pwd << "????? " << other << "?????????";

    
}