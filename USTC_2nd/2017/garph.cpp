#include<bits/stdc++.h>

using namespace std;

// bfs遍历整个图
void bfs(vector<vector<int>>& graph, vector<bool>& visited, int cur){
    visited[cur] = true;
    queue<int> que;
    que.push(cur);

    // 队列不空
    while(!que.empty()){
        cur = que.front(); que.pop();
        // 可达的节点加入队列    没访问过而且可达
        for(int i = 1; i <= visited.size() - 1; i++){
            if(!visited[i] && graph[cur][i]){
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

int main(){
    ifstream ifs("input4.txt");
    int n;
    ifs >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<bool> visited(n + 1, false);
    int src, dst;
    while(ifs >> src >> dst){
        graph[src][dst] = 1;
        graph[dst][src] = 1;
    }

    for(int i = 1; i <= n; i++){
        // 选取删除的点i
        // 尝试删除每一个点  然后bfs遍历剩下的点, 如果有不可达的点，说明这次的i就是要求的点
        // 拷贝
        vector<vector<int>> graph_copy = graph;
        vector<bool> visited_copy = visited;

        // 断开边
        for(int j = 1; j <= n; j++){
            graph_copy[i][j] = 0;
            graph_copy[j][i] = 0;
        }
        bfs(graph_copy, visited_copy, (i == 1 ? 2 : 1) );
        // 寻找不可达的点
        for(int j = 1; j <= n ; j++){
            // 记住不包含删除掉的i
            if(visited_copy[j] == false && j != i){
                cout << i;
                return 0;
            }
        }
    }
    cout << "not exist";
    
    ifs.close();
}