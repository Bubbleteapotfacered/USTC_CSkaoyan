#include<bits/stdc++.h>
using namespace std;

int main(){

    int kv[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char last[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0; i < s.size() - 1; i++){
        sum += kv[i] * (s[i] - '0');
        // cout << s[i] - '0' << " " << kv[i] <<  " " << sum << endl;

        // cout << sum << " ";
        
    }
    // cout << sum;
    
    if(s[17] == last[sum % 11]) cout << "YES";
    else cout << "NO";
}