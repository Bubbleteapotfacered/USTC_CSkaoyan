#include<bits/stdc++.h>

using namespace std;

int calculate(vector<char>& ops, vector<int>& nums){
    stack<int> st;
    st.push(nums[0]);
    for(int i = 0; i < ops.size(); i++){
        // 是加法的话直接放入
        if(ops[i] == '+') st.push(nums[i + 1]);
        else {
            // 是乘法的话
            // 取出前一个数  相乘再放入
            int pre = st.top(); st.pop();
            st.push(pre * nums[i + 1]);
        }
    }
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    return sum;
}

// 利用回溯法
// 构建所有可能的运算符组合
vector<char> path;
vector<char> op = {'+', '*'};
vector<vector<char>> op_combinations;
void backtracking(int n){
    if(path.size() == n){
        op_combinations.push_back(path);
        return ;
    }
    for(int i = 0; i < op.size(); i++){
        path.push_back(op[i]);
        backtracking(n);
        path.pop_back();
    }
}


int main(){
    vector<int> nums(4);
    backtracking(3);
    for(int i = 0; i < 4; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < op_combinations.size(); i++){
        if(calculate(op_combinations[i], nums) == 24){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
    
}