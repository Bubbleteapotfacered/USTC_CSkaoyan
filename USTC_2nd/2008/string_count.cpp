#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("4.in");
    string s;
    map<string, int> m;
    while(ifs >> s){
        m[s]++;
    }
    for(pair<string, int> ele : m){
        cout << ele.first << " " << ele.second << endl;
    }

    ifs.close();

}