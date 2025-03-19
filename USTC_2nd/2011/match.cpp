#include<bits/stdc++.h>

using namespace std;

bool isOK(string s, int start){
    // *是任意次
    // ?是0次或1次
    if(start >= s.size() || s[start++] != 'a') return false;
    if(start >= s.size() || s[start++] != 'b') return false;
    while(start < s.size() && s[start] == 'c'){
        start++;
    }
    int count_d = 0;
    while(start < s.size() && s[start] == 'd'){
        start++;
        count_d++;
    }
    if(count_d > 1) return false;
    else if(start >= s.size() || s[start] != 'e') return false;
    return true;

}


int main(){
    ifstream ifs("3.txt");
    string s;
    ifs >> s;
    for(int i = 0; i < s.size(); i++){
        if(isOK(s, i)){
            cout << "Find abc*d?e Match";
            return 0;
        } 
    }
    cout << "No Match";
    ifs.close();
}