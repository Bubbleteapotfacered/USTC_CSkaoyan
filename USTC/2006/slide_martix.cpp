#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int startindex, vector<int>& nums, int m){
        if(path.size() == m){
            res.push_back(path);
            return;
        }
        for(int i = startindex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(i + 1, nums, m);
            path.pop_back();
        }
    }
};



int main(){
    Solution s;
    vector<int> nums;
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        nums.push_back(i + 1);
    }
    
    s.backtracking(0,nums,m);

    for (int i = 0; i < s.res.size(); i++)
    {
        for(int j = 0; j < s.res[i].size(); j++){
            cout << s.res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}