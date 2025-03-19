#include<iostream>

using namespace std;

bool ishuiwen(string s){
    for(int i = 0, j = s.size() - 1; i < j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main(){
    int n;
    int count = 0;
    cin >> n;
    while( !ishuiwen(to_string(n))){
        count++;
        string temp = to_string(n);
        for(int i = 0, j = temp.size() - 1; i < j; i++, j--){
            char t = temp[i] ;
            temp[i] = temp[j];
            temp[j] = t;
        }
        n += stoi(temp);
    }
    cout << count;
}
