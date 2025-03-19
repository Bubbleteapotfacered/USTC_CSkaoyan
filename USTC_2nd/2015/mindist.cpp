#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input_4.txt");
    ofstream ofs("output_4.txt");
    int n, k;
    ifs.ignore(2); ifs >> n;
    // 回车也算一个字符
    ifs.ignore(3); ifs >> k;
    // 回车也算一个字符
    ifs.ignore(1);

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 10000));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, -1));
    for(int i = 1; i <= n; i++) graph[i][i] = 0;
    string s;
    while(getline(ifs, s)){
        istringstream iss(s);
        int src, dst, price;
        iss >> src;
        while(iss >> dst >> price){
            graph[src][dst] = price;
            path[src][dst] = src;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    vector<int> rever_way;
    int cur = n;
    while(cur != k){
        rever_way.push_back(cur);
        cur = path[k][cur];
    }
    // 此时cur = k
    while (cur != 1)
    {
        rever_way.push_back(cur);
        cur = path[1][cur];
    }
    rever_way.push_back(1);

    for(int i = rever_way.size() - 1; i >= 0; i--){
        cout << rever_way[i] << " ";
        ofs << rever_way[i] << " ";
    }
    

    ofs.close();
    ifs.close();
}