#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "one,two,three";
    istringstream iss(s);
    string part;
    while(getline(iss, part, ',')){
        cout << part << endl;
    }
}