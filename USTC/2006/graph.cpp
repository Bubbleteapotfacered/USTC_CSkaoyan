// 求最大连通分量

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
vector<int> path;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, int n){
    for(int i = 0; i < n; i++){
        if(graph[cur][i] == 1 && !visited[i]){
            path.push_back(i);
            visited[i] = true;
            dfs(graph, visited, i, n);
        }
    }
}
int main(){


    ifstream ifs("graph.in");
    ofstream ofs("graph.out");
    int n, k;
    ifs >> n >> k;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

    while(k--){
        // 存入无向图的结构
        // 邻接矩阵
        int s, d;
        ifs >> s >> d;
        graph[s][d] = 1;
        graph[d][s] = 1;
    }
    int max_count = 0;
    int max_index = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            // count记录联通分量的个数
            path.clear();
            visited[i] = true;
            path.push_back(i);
            dfs(graph,visited, i, n);
            res.push_back(path);
            if(path.size() > max_count) {
                max_index = count;
                max_count = path.size();
            }
            count ++;
        }
    }
    for(int i = 0; i < res[max_index].size(); i++){
        ofs << res[max_index][i] << " ";
    }
    ifs.close();
    ofs.close();

}