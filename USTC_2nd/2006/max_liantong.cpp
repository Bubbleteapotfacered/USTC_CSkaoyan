#include<bits/stdc++.h>

using namespace std;

// 用来记录从某个点出发能访问到的所有点
unordered_map<int, vector<int>> umap;
// 深搜dfs
// path记录了这次能访问到的所有节点
// count记录这次节点的数量
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur, int& count, vector<int>& path){
    path.push_back(cur);
    count++;
    for(int i = 0; i < graph.size(); i++){
        if(!visited[i] && graph[cur][i] == 1){
            visited[i] = true;
            dfs(graph, visited, i, count, path);
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
    int src, dst;
    for(int i = 0; i < k; i++){
        ifs >> src >> dst;
        graph[src][dst] = 1;
        graph[dst][src] = 1;
    }
    int max_val = 0;
    int max_index = 0;
    for(int i = 0; i < n; i++){
        // 没访问过的点
        if(!visited[i]){
            int count = 0;
            visited[i] = true;
            dfs(graph, visited, i, count, umap[i]);
            if(count > max_val){
                // 如果这个联通分量的大小大于大于已知的最大连通分量，那么更新最大联通分量，并且记录是从哪个顶点出发的
                max_val = count;
                max_index = i;
            }
        }   
    }
    // 输出最大联通分量
    for(int i = 0; i < umap[max_index].size(); i++){
        cout << umap[max_index][i] << " ";
        ofs << umap[max_index][i] << " ";
    }
    ifs.close();
    ofs.close();
}