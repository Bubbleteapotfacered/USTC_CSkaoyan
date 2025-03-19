#include<bits/stdc++.h>

using namespace std;

bool iszhishu(int num){
    int count = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0) count++;
    }
    return count <= 2;
}

int main(){
    ifstream ifs("4.in");
    ofstream ofs("4.out");
    int num;
    ifs >> num;
    int count = 0;
    for(int i = 1; i <= num / 2; i++){
        if(iszhishu(i) && iszhishu(num - i)) count++;
    }
    cout << count;
    ofs << count;

    ofs.close();
    ifs.close();
}