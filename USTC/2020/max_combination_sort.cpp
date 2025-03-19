#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("number.in");
    string s;
    vector<string> nums;
    while(ifs >> s){
        nums.push_back(s);
    }

    // 天才做法
    sort(nums.begin(), nums.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });

    for(string ele : nums){
        cout << ele;
    }
}