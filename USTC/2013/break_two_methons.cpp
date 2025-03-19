#include<bits/stdc++.h>

using namespace std;

bool iszhishi(int num){
    int count = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0) count++;
    }
    // 质数的因子个数小于等于2
    return count <= 2;
}


int main(){
    ifstream ifs("4.in");
    ofstream ofs("4.out");
    int num;
    ifs >> num;

    int count = 0;
    for(int i = 2; i <= num /2; i++){
        // 能够拆分成两个质数
        if(iszhishi(i) && iszhishi(num - i)){
            count++;
        }
    }

    ofs << count;

    ifs.close();
    ofs.close();

    return 0;
}