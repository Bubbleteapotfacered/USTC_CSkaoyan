#include<bits/stdc++.h>

using namespace std;


vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()){
        // 收集的条件，path长度为n
        res.push_back(path);
        return ;   
    }
    for(int i = 0; i < nums.size(); i++){
        // 求排列
        // 下标从0开始，因此path.size的位置的值不能是path.size + 1
        // 那么就是nums[i] != path.size() + 1
        // 那么就有 i != path.size()  因为 nums[i] = i + 1;
        if(used[i] || i == path.size()) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
}


int main(){
    // 求排列
    vector<int> nums;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        nums.push_back(i);
    }
    vector<bool> used(n, false);
    backtracking(nums, used);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}