#include<bits/stdc++.h>


using namespace std;


int main(){
    ifstream ifs("number.in");
    

    vector<string> nums;
    string s;
    while(ifs >> s){
        nums.push_back(s);
    }
    sort(nums.begin(), nums.end(),[](string& a, string& b){
        return a + b > b + a;
    });
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }

    ifs.close();
}