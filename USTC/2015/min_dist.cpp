#include<bits/stdc++.h>

using namespace std;


int main(){
    ifstream ifs("input_4.txt");
    ofstream ofs("output_4.txt");
    string s;
    ifs >> s;
    int n = s[2] - '0';
    ifs >> s;
    int k = s[2] - '0';
    int src = 1, dst = n;
    // 10001表示不可达
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 10001));
    vector<vector<int>> D(n + 1);
    // path[i][j]用来表示i节点到j节点的最后一个中间节点
    vector<vector<int>> path(n + 1, vector<int>(n + 1, -1));
    for(int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    while(getline(ifs, s)){
        istringstream iss(s);
        int from, to, price;
        iss >> from;
        while(iss >> to >> price){
            graph[from][to] = price;
            path[from][to] = from;
        }
    }
    D = graph;
    // Floyd算法
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    vector<int> way;
    int cur = dst;
    while(cur != k){
        way.push_back(cur);
        cur = path[k][cur];
    }
    while(cur != src){
        way.push_back(cur);
        cur = path[src][cur];
    }
    way.push_back(cur);

    for(int i = way.size() - 1; i >= 0; i--){
        cout << way[i];
        ofs << way[i];
        if(i != 0) {
            ofs << " ";
            cout << " ";
        }
    }
    ifs.close();
    ofs.close();
}