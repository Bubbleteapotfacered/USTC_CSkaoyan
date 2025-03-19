#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("1.in");
    ofstream ofs("1.out");
    int max_val = 0;
    int val;
    while(ifs >> val){
        max_val = max(max_val, val);
    }
    ofs << max_val;
    ifs.close();
    ofs.close();
    return 0;
}