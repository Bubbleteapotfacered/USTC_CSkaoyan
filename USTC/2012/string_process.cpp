#include<bits/stdc++.h>
using namespace std;


int main(){
    ifstream ifs("string.in");
    double s1, s2;
    ifs >> s1 >> s2;
    double res = s1 + s2;
    
    ofstream ofs("string.out");

    ofs << scientific <<res;


    ifs.close();
    ofs.close();

    
}