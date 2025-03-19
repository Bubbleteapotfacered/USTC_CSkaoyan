#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("6.in");
    ofstream ofs("6.out");
    // 直接暴力
    
    string s1, s2;
    ifs >> s1 >> s2;
    int start = 0;

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0, k = i; j < s2.size() && k < s1.size(); j++, k++){
            if(s2[j] != s1[k]) break;
            else if(s2[j] == s1[k] && j == s2.size() - 1){
                start = i;
            }
        }
    }
    if(start== 0) ofs << 0;
    else if(start != 0) ofs << start + 1 << " " << start + s2.size();


    ifs.close();
    ofs.close();
    
}