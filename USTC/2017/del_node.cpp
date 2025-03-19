#include<bits/stdc++.h>

using namespace std;


// 能不能走遍
// bfs遍历图
void bfs(vector<vector<int>>& graph, int cur, vector<bool>& visited){
    queue<int> que;
    que.push(cur);
    visited[cur] = true;
    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(int i = 1; i < graph.size(); i++){
            if(!visited[i] && graph[cur][i] == 1){
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
    int s, t;
    while(ifs >> s >> t){
        graph[s][t] = 1;
        graph[t][s] = 1;
    }

    int flag = 0;
    int node = 0;
    
    for(int i = 1; i <= n; i++){
        // 删除节点i
        vector<vector<int>> g = graph;
        vector<bool> v = visited;
        for(int j = 1; j <= n; j++){
            // 删掉i这点所连接的边
            if(g[i][j] == 1) {
                g[i][j] = 0;
                g[j][i] = 0;
            }
        }
        bfs(g, i == 1 ? 2 : 1, v);

        for(int j = 1; j <= n; j++){
            // 判断是否能遍历整个图
            if(j == i) continue;
            if(!v[j]) {
                flag = 1;
                node = i;
                break;
            }
        }
        if(flag == 1) break;
    }
    if(flag == 1){
        cout << node;
    }else{
        cout << "not exist";
    }

    return 0;

}