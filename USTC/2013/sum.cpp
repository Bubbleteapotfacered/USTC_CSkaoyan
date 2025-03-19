#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("2.in");
    ofstream ofs("2.out");

    int sum = 0;
    int val;
    while(ifs >> val){
        sum += val;
    }
    ofs << sum;

    ifs.close();
    ofs.close();
    return 0;
}