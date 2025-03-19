#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("road.in");
    ofstream ofs("road.out");
    int n, m, src, dst, from, to, price;
    ifs >> n >> m >> src >> dst;

    vector<vector<int>> graph(n+1, vector<int>(n+1, 10001));
    // 记录最小距离
    vector<int> minDist(n + 1, 10001);
    // 记录上一个节点
    vector<int> parent(n + 1, -1);
    // 记录是否在最短路径内
    vector<bool> visited(n + 1, false);

    for(int i = 1; i <= n; i++) graph[i][i] = 0;

    for(int i = 1; i <= m; i++){
        ifs >> from >> to >> price;
        // cout << from << to << price << endl;
        graph[from][to] = price;
        graph[to][from] = price;
    }
    // 初始化
    minDist[src] = 0;
    // dijkstra三部曲   1. 找最小的距离  2.加入最短路径   3.更新

    // 循环n次, 一次加入一个点
    for(int i = 1; i <= n; i++){
        // 1.
        int min_val = 10001;
        int cur = -1;
        for(int j = 1; j <= n; j++){
            if(!visited[j] && minDist[j] < min_val) {
                // 1.找到最小的距离
                min_val = minDist[j];
                cur = j;
            }
        }
        if(cur == -1){
            // 已经找不到了
            break;
        }
        // 2.加入最短路径
        visited[cur] = true;

        // 3.更新距离
        for(int j = 1; j <= n; j++){
            if(!visited[j] && minDist[j] > minDist[cur] + graph[cur][j]){
                minDist[j] = minDist[cur] + graph[cur][j];
                // 记录上一个节点
                parent[j] = cur;
            }
        }
    }
    // 不可达
    if(minDist[dst] == 10001){
        ofs << "can't arrive";
        return 0;
    }
    cout << minDist[dst] << endl;
    ofs << minDist[dst] << endl;
    int cur = dst;
    vector<int> rev_path;
    while(cur != src){
        rev_path.push_back(cur);
        cur = parent[cur];
    }
    rev_path.push_back(src);

    for(int i = rev_path.size() - 1; i >= 0; i--){
        ofs << rev_path[i];
        cout << rev_path[i];
        if(i != 0) {
            ofs << " ";
            cout << " ";
        }
    }
    ifs.close();
    ofs.close();

    
}