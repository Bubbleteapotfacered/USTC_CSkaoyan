#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int s;
    int t;
    int val;
};
int n;
vector<int> father;

void init(){
    for(int i = 0; i < n; i++){
        father.push_back(i);
    }
}

int find(int u){
    return father[u] == u ? u : father[u] = find(father[u]);
}
void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return ;
    else father[v] = u;
}


int main(){
    ifstream ifs("3.in");
    ofstream ofs("3.out");
    int s, t, w;
    ifs >> n;
    // cout << n << endl;
    init();
    vector<Edge> Edges;

    while(ifs >> s >> t >> w){
        // cout << s << t << w << endl;
        Edges.push_back({s, t, w});
    }

    // 排序
    sort(Edges.begin(), Edges.end(), [](const Edge& a, const Edge& b){
        return a.val < b.val;
    });
    
    for(Edge e : Edges){
        // 成环了
        if(find(e.s) == find(e.t)){
            continue;
        }else{
            // 没成环
            join(e.s, e.t);
            // cout << e.s << " -- " << e.t << " :" << e.val << endl;
            ofs << e.s << " -- " << e.t << " :" << e.val << endl;

        }
    }








    ofs.close();
    ifs.close();

}