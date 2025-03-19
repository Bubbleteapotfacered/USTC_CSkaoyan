#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input1.txt");
    string s;
    vector<string> res;
    while(ifs >> s){
        if(s[0] >= 'a' && s[0] <= 'z'){
            s[0] -= 32;
        }
        res.push_back(s);
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
    }

    ifs.close();
}