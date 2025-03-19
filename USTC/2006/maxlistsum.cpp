#include<iostream>
#include<fstream>
#include<vector>


using namespace std;

int main(){
    ifstream ifs("number.in");
    int num;
    vector<int> nums;
    while(ifs >> num){
        nums.push_back(num);
    }

    int sum = 0;
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        // 加上
        sum += nums[i];
        // 如果是负数，那么只会让后面变小，重置为0
        if(sum < 0) sum = 0;
        // 如果是正数，有可能更大，而且会促进下一个值
        else {
            if(sum > res) res = sum;
        }
    }
    ofstream ofs("number.out");
    ofs << res;
    ofs.close();
    ifs.close();



}