#include<bits/stdc++.h>

using namespace std;

int calculate(vector<int>& nums, string fh){
    int sum = 0;
    vector<int> path;
    path.push_back(nums[0]);
    for(int i = 0; i < 3; i++){
        if(fh[i] == '+') path.push_back(nums[i + 1]);
        else {
            // 乘法
            int num = path.back();
            path.pop_back();
            path.push_back(num * nums[i + 1]);
        }
    }
    for(int i = 0; i < path.size(); i++){
        sum += path[i];
    }
    return sum;   
}

int main(){
    vector<int> nums(4,0);
    for(int i = 0; i < 4; i++){
        int num;
        cin >> num;
        nums[i] = num;
    }
    char fuhao[2] = {'+','*'};
    int count = 0;
    vector<string> fh(8,"");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                fh[count].push_back(fuhao[i]);
                fh[count].push_back(fuhao[j]);
                fh[count++].push_back(fuhao[k]); 
            }
        }
    }
    for(int i = 0; i < 8; i++){
        if(calculate(nums, fh[i]) == 24){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}

