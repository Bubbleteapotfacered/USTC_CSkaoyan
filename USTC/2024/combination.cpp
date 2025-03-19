#include<bits/stdc++.h>

using namespace std;

vector<int> path;
vector<vector<int>> res;
void backtracking(vector<int>& nums, vector<bool>& visited){
    if(path.size() == nums.size()){
        // 收集结果
        res.push_back(path);
        return ;
    }
    // 明显是排列, 从0开始
    for(int i = 0; i < nums.size(); i++){
        // path.size() + 1 表示现在要放的位置(从1开始)
        // nums[i] 表示现在要放的数
        // 根据题目  所有异位的组合, 那么要放的数   不等于  要放的位置
        // 即nums[i] != path.size() + 1
        // 又nums[i] == i + 1;
        // 有i != path.size()
        // 异位 + 没用过
        if(i == path.size() || visited[i]) continue;

        visited[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, visited);
        visited[i] = false;
        path.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        nums.push_back(i + 1);
    }

    vector<bool> visited(n, false);
    backtracking(nums, visited);

    for(int i = 0; i < res.size(); i++){
        cout << "{";
        for(int j = 0; j < res[i].size(); j++){
            if(j != 0) cout << ",";
            cout << res[i][j];
        }
        cout << "}" << endl;
    }
    

}