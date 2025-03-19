#include<bits/stdc++.h>

using namespace std;

long long res = 0;
vector<string> path;
void backtracking(vector<string>& nums, vector<bool>& visited){
    if(path.size() == nums.size()){
        string num = "";
        for(int i = 0; i < path.size(); i++) num += path[i];
        res = max(res, stoll(num));
        return ;
    }
    for(int i = 0; i < nums.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, visited);
        path.pop_back();
        visited[i] = false;
    }
}

// 回溯暴力
int main(){
    ifstream ifs("number.in");
    string s;
    vector<string> nums;
    while(ifs >> s){
        nums.push_back(s);
    }

    vector<bool> visited(nums.size(), false);

    backtracking(nums, visited);

    cout << res;

    ifs.close();
}