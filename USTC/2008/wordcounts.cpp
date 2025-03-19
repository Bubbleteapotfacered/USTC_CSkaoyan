#include<bits/stdc++.h>

using namespace std;


int main(){

    map<string, int> map;
    ifstream ifs("4.in");
    ofstream ofs("4.out");
    string s;
    while(ifs >> s){
        // map会自动排序
        map[s]++;
    }
    for(pair<string, int> ele : map){
        // map会自动排序，而且字典索引顺序可以用ASCII码来比较
        cout << ele.first << " " << ele.second << endl;
        ofs << ele.first << " " << ele.second << endl;
    }
}