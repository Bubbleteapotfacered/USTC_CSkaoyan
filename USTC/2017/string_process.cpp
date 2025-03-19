#include<bits/stdc++.h>

using namespace std;


int main(){
    ifstream ifs("input1.txt");
    vector<string> strs;
    string s;
    int index = 0;
    while(ifs >> s){
        strs.push_back(s);
        if(s[0] <= 'z' && s[0] >= 'a'){
            s[0] -= 32;
        }
        if(index++ != 0) cout << " ";
        cout << s;
    }

    ifs.close();
}