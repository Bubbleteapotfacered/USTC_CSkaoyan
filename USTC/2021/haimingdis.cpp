#include<bits/stdc++.h>

using namespace std;

int main(){
    long long  m , n;
    cin >> m >> n;

    long long  xor_val = m ^ n;
    cout << xor_val << endl;
    int hm_dis = 0;
    while(xor_val > 0){
        if(xor_val % 2 == 1) hm_dis++;
        xor_val /= 2;
    }
    cout << hm_dis;

}