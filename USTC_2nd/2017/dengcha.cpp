#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input3.txt");
    vector<int> nums;
    int num;
    while(ifs >> num){
        nums.push_back(num);
    }


    int max_val = 1;
    // 遍历公差
    for(int k = 1; k < nums[nums.size()-1]; k++){
        // 遍历起点
        for(int i = 0; i < nums.size(); i++){
            // 遍历长度
            int count = 1;
            int pre = nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] - pre == k){
                    count ++;
                    pre = nums[j];
                    max_val = max(max_val, count);
                }else if(nums[j] - pre > k) break;
            }
        }
    }

    cout << max_val;




    ifs.close();
}