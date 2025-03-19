#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input2.txt");
    int m;
    ifs >> m;
    unordered_map<string, int> umap;
    
    string s;
    while(getline(ifs, s)){
        string id, starttime, endtime;
        // ifs >> id >> starttime >> endtime;
        // string start_hour, start_minute, end_hour, end_minute;
        // // 开始的时间
        // istringstream iss1(starttime);
        // getline(iss1, start_hour, ':');
        // getline(iss1, start_minute, ':');
        // // 结束的时间
        // istringstream iss2(endtime);
        // getline(iss2, end_hour, ':');
        // getline(iss2, end_minute, ':');

        // int begin = stoi(start_hour) * 60 + stoi(start_minute);
        // int end = stoi(end_hour) * 60 + stoi(end_minute);
        // 计算分钟数
        ifs >> id;
        int start_hour, start_minute, end_hour, end_minute;
        ifs >> start_hour; ifs.ignore(1);
        ifs >> start_minute;
        ifs >> end_hour; ifs.ignore(1);
        ifs >> end_minute;
        
        int begin = start_hour * 60 + start_minute;
        int end = end_hour * 60 + end_minute;
        umap[id] += (end - begin + 60 * 24) % (60 * 24);
    }
    // 记录最大的时长  和  学号
    int max_val = 0;
    string id;
    for(pair<string, int> ele : umap){
        if(ele.second > max_val){
            max_val = ele.second;
            id = ele.first;
        }
    }
    cout << id;


    ifs.close();

}