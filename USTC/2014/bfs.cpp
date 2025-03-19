#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited){
    // 默认从1开始
    queue<int> que;
    que.push(1);
    visited[1] = true;

    while(!que.empty()){
        // 队列中的已经是访问过的
        // 接下来要寻找没有访问过的
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        for(int i = 1; i <= graph.size() - 1; i++){
            if(graph[cur][i] == 1 && !visited[i]){
                // 没被访问过, 可以到达
                visited[i] = true;
                que.push(i);
            }
        }
    }
}
int main(){
    ifstream ifs("graph.in");
    int n;
    int from, to;
    ifs >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<bool> visited(n + 1, false);

    while(ifs >> from >> to){
        // 0 0表示结束
        if(from == 0 && to == 0) break;

        graph[from][to] = 1;
        graph[to][from] = 1;        
    }
    
    bfs(graph, visited);


    ifs.close();



}