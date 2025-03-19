#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
vector<int> path;
void backtracking(vector<int>& nums, int& m, int start){
    if(path.size() == m){
        res.push_back(path);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        path.push_back(nums[i]);
        backtracking(nums, m, i + 1);
        path.pop_back();
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        nums[i] = i + 1;
    }
    backtracking(nums, m, 0);
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            if(j != 0) cout << " ";
            cout << res[i][j];
        }
        cout << endl;
    }

}