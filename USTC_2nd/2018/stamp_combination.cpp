#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(int& a, int& b){
        return a > b;
    }
};

// 用来记录个数
int num = 0;
// 记录当前的总价值
int sum = 0;
// 记录当前的个数
int stamp_count = 0;
// 标记是否找到
bool find_num = false;
void backtracking(vector<int>& stamps, int startindex, int m){
    // stamps从大到小，第一个找到的一定是最少的数量
    // 用find_num来标记是否找到

    // 已经找到，后续不需要再找
    if(find_num) return ;
    if(sum > m) return;
    if(sum == m){
        // 找到直接返回
        find_num = true;
        num = stamp_count;
        return ;
    }
    // 回溯模板
    for(int i = startindex; i < stamps.size(); i++){
        sum += stamps[i];
        stamp_count++;
        // 可以重复用，传入startindex = i
        backtracking(stamps, i, m);
        sum -= stamps[i];
        stamp_count--;
    }
}

int main(){
    int m, n;
    ifstream ifs("input3.txt");
    ifs >> m >> n;
    vector<int> stamps;
    for(int i = 0; i < n; i++){
        int stamp_val;
        ifs >> stamp_val;
        stamps.push_back(stamp_val);
    }

    // 从大到小排序
    sort(stamps.begin(), stamps.end(), cmp());
    backtracking(stamps, 0, m);
    cout << num;
    
    ifs.close(); 
}