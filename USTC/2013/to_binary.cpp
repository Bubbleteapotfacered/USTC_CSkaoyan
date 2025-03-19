#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("3.in");
    ofstream ofs("3.out");

    int num;
    ifs >> num;

    vector<int> bin;
    while(num > 0){
        bin.push_back(num % 2);
        num /= 2;
    }
    for(int i = bin.size() - 1; i >= 0; i--){
        ofs << bin[i];
    }
    


    
    ifs.close();
    ofs.close();
}