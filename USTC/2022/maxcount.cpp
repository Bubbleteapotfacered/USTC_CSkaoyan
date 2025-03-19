#include<iostream>

using namespace std;


int main(){

    string s;

    getline(cin, s);

    int count = 0;
    int max_len = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' ') {
            count ++;
            max_len = max(count, max_len);
        }
        else count = 0;
    }
    cout << max_len;

}