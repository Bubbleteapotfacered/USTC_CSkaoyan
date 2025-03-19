#include<bits/stdc++.h>
using namespace std;


int main(){
    ifstream ifs("road.in");
    ofstream ofs("road.out");

    int n, m, src ,dst;
    int from, to, price;
    ifs >> n >> m >> src >> dst;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 10001));
    // 记录路径
    vector<vector<int>> path(n+1, vector<int>(n+1, -1));
    for(int i = 1; i <= m; i++){
        ifs >> from >> to >> price;
        graph[from][to] = price;
        graph[to][from] = price;
        path[from][to] = from;
        path[to][from] = to;
    }
    for(int i = 1; i <= n; i++) graph[i][i] = 0;
    vector<vector<int>> D(n+1);
    D = graph;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    
    if(D[src][dst] != 10001){
        ofs << D[src][dst] << endl;
        cout << D[src][dst] << endl;
    }else{
        ofs << "can't arrive" << endl;
        cout << "can't arrive" << endl;
    }
    // 此时path[i][j]的含义为从i到j最短路径的倒数第二个节点,  如果有最短路径1->2->3->4   那么path[1][4]为3
    int last = dst;
    vector<int> reverse_path;
    while(last != src){
        reverse_path.push_back(last);
        last = path[src][last];
    }
    // 最后放入src
    reverse_path.push_back(src);
    for(int i = reverse_path.size()-1; i >= 0; i--){
        cout << reverse_path[i] << " ";
        ofs << reverse_path[i];
        if(i != 0) ofs << " ";
    }
    ifs.close();
    ofs.close();
}