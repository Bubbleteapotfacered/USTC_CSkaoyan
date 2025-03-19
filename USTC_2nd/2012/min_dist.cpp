#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("road.in");
    ofstream ofs("road.out");
    // 直接floyd算法

    int n, m, src, dst;
    ifs >> n >> m >> src >> dst;
    // 用来记录最短距离
    vector<vector<int>> distance(n + 1, vector<int>(n + 1, 10000));
    // 用来记录前一个节点
    vector<vector<int>> pre (n + 1, vector<int>(n + 1, -1));
    // 初始化distance
    for(int i = 1;i <= n; i++) {
        distance[i][i] = 0;
        pre[i][i] = i;
    }
    
    int from, to, price;
    for(int i = 1; i <= m; i++){
        ifs >> from >> to >> price;
        // cout << from << to << price;
        distance[from][to] =  price;
        pre[from][to] = from;
    }
    // Floyd算法
    // 遍历每个顶点，将其当作中间点
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }
    // 不可达
    if(distance[src][dst] == 10000) {
        ofs << "can't arrive";
        ofs.close();
        return 0;
    }
    // 可达  输出长度
    ofs << distance[src][dst] << endl;

    // 用来记录dst到src的路径
    vector<int> path;
    int cur = dst;

    // 寻找dst到src的路径
    while(cur != src){
        path.push_back(cur);
        cur = pre[src][cur];
    }
    // 此时cur = src
    path.push_back(src);
    for(int i = path.size() - 1; i >= 0; i--){
        ofs << path[i] << " ";
    }
    ofs.close();    
}
