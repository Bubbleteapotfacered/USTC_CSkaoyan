#include<bits/stdc++.h>

using namespace std;


// 二刷
int main(){
    int num;

    cin >> num;
    int copy = num;
    vector<int> bin;
    while(num > 0){
        bin.push_back(num % 2);
        num /= 2;
    }
    int count = 0;

    vector<int> res;
    for(int i = 0; i < bin.size(); i++){
        if(bin[i] == 1) {
            res.push_back(i);
            count++;
        }
    }

    if(count != 2){
        cout << "NO" << endl;
    }else{
        cout << copy << " = 2^" << res[0] << " + 2^" << res[1];
    }

}