#include<bits/stdc++.h>
using namespace std;

int main(){
    int d ;
    cin >> d;
    int count = 0;
    while(d > 0){
        if(d % 2 == 1) count++;
        d /= 2;
    }
    cout << count;
    return 0;
}