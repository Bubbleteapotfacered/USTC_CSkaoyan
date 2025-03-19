#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> res;

void print(vector<vector<char>>& res){

    cout << "{";
    for(int i = 0; i < res.size(); i++){
        
        for(int j = 0; j < res[i].size(); j++){
            if(j == 0) cout << "{";
            cout << res[i][j];
            if(j != res[i].size() - 1) cout << ",";
            if(j == res[i].size() - 1) cout << "}";
        }
        if(i != res.size() - 1) cout << ",";
    }
    cout << "}";
    cout << endl;
}

void backtracking(vector<char>& elements, int start){
    // 到最后一个元素   收集结果
    if(start == elements.size()){
        print(res);
        return ;
    }
    // 加入已经有的集合
    for(int i = 0; i < res.size(); i++){
        res[i].push_back(elements[start]);
        // 下一个
        backtracking(elements, start + 1);
        res[i].pop_back();
    }
    // 自身一个集合
    res.push_back({elements[start]});
    backtracking(elements, start + 1);
    res.pop_back();
}

int main(){
    ifstream ifs("set.in");

    vector<char> elements;
    char ele;
    while(ifs >> ele){
        elements.push_back(ele);
    }
    backtracking(elements, 0);

    ifs.close();
}