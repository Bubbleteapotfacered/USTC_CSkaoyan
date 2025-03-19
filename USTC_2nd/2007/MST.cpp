#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int src;
    int dst;
    int price;
};

vector<int> father;
void init(int n){
    for(int i = 0; i < n; i++){
        father.push_back(i);
    }
}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}
bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}
void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    else father[v] = u;
}
int main(){
    // 用并查集来判断是否产生回路
    ifstream ifs("3.in");
    ofstream ofs("3.out");
    int n, src, dst, price;
    vector<Edge> Edges;
    ifs >> n;
    while(ifs >> src >> dst >> price){
        Edges.push_back({src, dst, price});
    }
    // 根据权值从小到大排序
    sort(Edges.begin(), Edges.end(),[](const Edge& a, const Edge& b){
        return a.price < b.price;
    });

    init(n);

    // 实行克鲁斯卡尔算法
    for(Edge e : Edges){
        int src = e.src;
        int dst = e.dst;
        int price = e.price;
        // 会产生回路，跳过
        if(isSame(src,dst)) continue;
        else {
            // 不会产生回路， 加入边集
            join(src, dst);
            ofs << src << " -- " << dst << " : " << price << endl;
        }
    }


    ifs.close();
    ofs.close();
}