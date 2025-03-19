#include<bits/stdc++.h>

using namespace std;

int main(){
    int count = 0;
    int num;
    cin >> num;
    while(num > 0){
        if(num % 2 == 1) count++;
        num /= 2;
    }
    cout << count;

    return 0;
}