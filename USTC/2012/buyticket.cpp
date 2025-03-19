#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    ifstream ifs("ticket.in");
    ofstream ofs("ticket.out");
    ifs >> n >> m;

    // n为订票请求, m为载客人数
    vector<vector<int>> t;
    int a, b, k;

    // 记录站点的最大值
    int max_val = 0;
    for(int i = 1; i <= n; i++){
        ifs >> a >> b >> k;
        max_val = max(max_val, a);
        max_val = max(max_val, b);
        t.push_back({a, b, k});
    }

    // 记录火车在这段区间的人数
    vector<int> trainstop(max_val + 1, 0);

    for(int i = 0; i < t.size(); i++){
        int from = t[i][0];
        int to = t[i][1];
        int nums = t[i][2];
        // 表示票够
        int flag = 1;
        // 查找票够不够
        for(int j = from; j < to; j++){
            if(nums + trainstop[j] > m){
                // 票不够
                flag = 0;
                break;
            }
        }
        if(flag){
            // 如果票够
            for(int j = from; j < to; j++){
                // 加上人数
                trainstop[j] += nums;
            }
        }
        ofs << flag << endl;
    }
    ifs.close();
    ofs.close();
}