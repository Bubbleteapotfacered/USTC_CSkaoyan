#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input2.txt");

    int m;
    ifs >> m;
    // 吃掉回车
    ifs.ignore();

    // string存学号， int存分钟数
    unordered_map<string, int> umap;
    string s;
    while(m--){

        getline(ifs, s);
        istringstream iss(s);
        // 存学号
        string stuid;
        iss >> stuid;
        // 存起始时间和结束时间
        int begin_hour, begin_minute, end_hour, end_minute;
        iss >> begin_hour; iss.ignore(1); iss >> begin_minute;
        iss >> end_hour; iss.ignore(1); iss >> end_minute;
        // 计算分钟差 
        int start_time = begin_hour * 60 + begin_minute;
        int end_time = end_hour * 60 + end_minute;
        // 存入map中对应学号的位置
        umap[stuid] += (end_time - start_time + 60 * 24) % (60 * 24);
    }
    string res = "";
    int max_time = 0;

    // 遍历整个umap寻找最大的分钟数
    for(pair<string, int> ele : umap){
        if(ele.second > max_time){
            max_time = ele.second;
            res = ele.first;
        }
    }

    cout  << res;

    ifs.close();
}