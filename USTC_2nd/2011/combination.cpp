#include<bits/stdc++.h>

using namespace std;

int main(){
    int x, y, k;
    cin >> x >> y >> k;
    for(int i = 0; i <= x && i <= 8; i++){
        for(int j = 0; j <= y && j <= 8 - i; j++){
            if(8 - i - j <= k){
                cout << i<< " " << j << " " << 8-i-j << endl;
            }
        }
    }
}