#include<bits/stdc++.h>
using namespace std;

int main(){
    // 利用拓扑排序
    ifstream ifs("task.in");
    ofstream ofs("task.out");
    string s;

    // 暂时存放输入
    vector<string> Tasks;
    while(getline(ifs, s)){
        Tasks.push_back(s);
    }
    // 用来记录入度
    vector<int> indegree(Tasks.size(), 0);
    // 用来记录依赖关系
    unordered_map<int, vector<int>> umap;

    for(int i = 0; i < Tasks.size(); i++){
        for(int j = 5; j < Tasks[i].size(); j++){
            // Tasks[i][4]是前序任务的下标
            if(isdigit(Tasks[i][j])){
                // 记录依赖关系
                umap[Tasks[i][4] - '0'].push_back(Tasks[i][j] - '0');
                // 记录入度
                indegree[Tasks[i][j] - '0']++;
            } 
        }
    }
    // 用来记录结果
    vector<int> res;
    queue<int> que;
    // 寻找入度为0的节点
    for(int i = 0; i < Tasks.size(); i++){
        if(indegree[i] == 0) que.push(i);
    }

    while(!que.empty()){
        // 记录顺序
        int cur = que.front(); que.pop();
        res.push_back(cur);
        for(int i = 0; i < umap[cur].size(); i++){
            
            // 对应后序任务的入度减1
            indegree[umap[cur][i]]--;
            // 入度为0加入队列
            if(indegree[umap[cur][i]] == 0) que.push(umap[cur][i]);
        }

    }
    for(int i = 0; i < res.size(); i++){
        cout << "Task" << res[i] << " ";
        ofs << "Task" << res[i] << " ";
    }

    ofs.close();
    ifs.close();
}