#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int cur){
    visited[cur] = true;
    queue<int> que;
    que.push(cur);
    while(!que.empty()){
        cur = que.front();que.pop();
        cout << cur << " ";
        for(int i = 1; i <= graph.size() - 1; i++){
            if(!visited[i] && graph[cur][i] == 1){
                visited[i] = true;
                que.push(i);
            }
        }
    }
}

int main(){
    ifstream ifs("graph.in");
    int n;
    ifs >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<bool> visited(n + 1, false);
    int src, dst;
    
    while(ifs >> src >> dst){
        if(src == 0 && dst == 0) break;
        graph[src][dst] = 1;
        graph[dst][src] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(graph, visited, i);
        }
    }


    ifs.close();
}