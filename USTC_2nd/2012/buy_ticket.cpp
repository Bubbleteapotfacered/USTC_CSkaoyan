#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("ticket.in");

    int n, m;
    ifs >> n >> m;

    // 记录每个站点的人数
    vector<int> stop_persons(10000, 0);
    int src, dst, val;
    for(int k = 1; k <= n; k++){
        ifs >> src >> dst >> val;
        // 判断是否可以买票
        bool canbuy = true;
        for(int i = src ; i < dst; i++){
            if(stop_persons[i] + val > m){
                // 超过最大载客人数
                canbuy = false;
                break;
            }
        }
        if(canbuy){
            // 满足要求
            for(int i = src ; i < dst; i++){
               stop_persons[i] += val;
            }
        }
        cout << canbuy << endl;
    }

    ifs.close();
}