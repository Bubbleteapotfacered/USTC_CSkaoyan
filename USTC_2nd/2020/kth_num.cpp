#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("array.in");
    int n, k;
    ifs >> n >> k;
    // 小顶堆
    // priority_queue<int, vector<int>, greater<int>> pq;
    // int num;
    // for(int i = 1; i <= n; i++){
    //     // 收集最大的n - k + 1个数
    //     ifs >> num;
    //     if(pq.size() < n - k + 1){
    //         pq.push(num);
    //     }else if(pq.size() == n - k + 1 & num > pq.top()){
    //         pq.pop();
    //         pq.push(num);
    //     }
    // }


    // 大顶堆
    priority_queue<int> pq_max;
    int num;
    for(int i = 1; i <= n; i++){
        ifs >> num;
        if(pq_max.size() < k){
            pq_max.push(num);
        }else if(pq_max.top() > num){
            // 存前k小的树
            pq_max.pop();
            pq_max.push(num);
        }
    }
    cout << pq_max.top();
    ifs.close();
    return 0;

}