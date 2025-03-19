#include<bits/stdc++.h>

using namespace std;

// 记录最小个数
int res = INT_MAX;
// 记录当前面值
int sum = 0;
// 记录当前邮票个数
int num = 0;

void backtracking(vector<int>& stamps, int start, int total){
    if(sum == total){
        // 符合要求, 收集结果, 求最小的邮票个数
        res = min(num, res);
        return ;
    }
    for(int i = start; i < stamps.size(); i++){
        // 保证不大于total
        if(sum + stamps[i] > total) continue;

        sum += stamps[i];
        num++;
        // 还是从当前邮票开始, 一是因为还可能使用到, 二是因为之前的不符合要求或者已经遍历过了
        backtracking(stamps, i, total);
        num--;
        sum -= stamps[i];
    }

}

int main(){
    ifstream ifs("input3.txt");

    // 总面值，邮票种类
    int total, types;
    ifs >> total >> types;

    vector<int> stamps;
    int stamp;
    while(types--){
        ifs >> stamp;
        stamps.push_back(stamp);
    }

    // 降序排列， 保证先使用大的
    sort(stamps.begin(), stamps.end(), greater<int>());

    backtracking(stamps, 0, total);

    if(res == INT_MAX){
        cout << 0;
        return 0;
    }
    cout << res;
    ifs.close();
}