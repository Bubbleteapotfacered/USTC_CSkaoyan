#include<bits/stdc++.h>

using namespace std;

bool ishuiwen(string s){
    for(int i = 0, j = s.size() - 1; i < j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main(){
    string num;
    cin >> num;
    int count = 0;
    while(!ishuiwen(num)){
        count++;
        int num_i = stoi(num);
        reverse(num.begin(), num.end());
        num_i += stoi(num);
        num = to_string(num_i);
    }
    cout << count;

}