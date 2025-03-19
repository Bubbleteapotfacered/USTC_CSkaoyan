#include<bits/stdc++.h>

using namespace std;

int main(){

    ifstream ifs("task.in");

    unordered_map<int,vector<int>> umap;
    vector<string> taskStr;
    string s;

    while(ifs >> s){
        // 每一行任务
        taskStr.push_back(s);
    }
    // 任务总数量
    int n = taskStr.size();

    // 用来存放每一行的数字
    vector<vector<int>> tasks(n);

    for(int i = 0; i < taskStr.size(); i++){
        for(int j = 0; j < taskStr[i].size(); j++){
            // 把每一行的数字存入tasks
            // 如第一行存入0 1 2
            // 第二行存入 1 3
            // 第三行存入 2
            // 第四行存入 3
            if(isdigit(taskStr[i][j])) tasks[i].push_back(taskStr[i][j] - '0');
        }
    }
    vector<int> indegree(n, 0);
    for(int i = 0; i < tasks.size(); i++){
        vector<int> e = tasks[i];
        if(e.size() >= 1){
            for(int j = 1; j < e.size(); j++){
                indegree[e[j]]++;
                umap[i].push_back(e[j]);
            }
        }
    }
    queue<int> que;
    // 一开始入度为0
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }
    // 后续处理
    vector<int> result;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        for(int i = 0; i < umap[cur].size(); i++){
            indegree[umap[cur][i]]--;
            if(indegree[umap[cur][i]] == 0){
                que.push(umap[cur][i]);
            }
        }
    }
    ofstream ofs("task.out");

    for(int i = 0; i < result.size(); i++){
        cout << "Task" << result[i] << " ";
        ofs << "Task" << result[i] << " ";
    }
    ofs.close();
    ifs.close();
}