#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input.txt");
    vector<string> res;
    string s;

    while(getline(ifs, s)){
        res.push_back(s);
    }
    unordered_set<int> del;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            // 如果是！ 移除前面一个
            if(j > 0 && res[i][j] == '!') {
                res[i][j] = '1';
                res[i][j - 1] = '1';
            }
            // 如果是*  删除前一行
            if(res[i][j] == '*' && i > 0) {
                del.insert(i - 1);
                res[i][j] = '1';
            }
            // 如果是>  前面一个单词首字符大小写转换
            if(res[i][j] == '>'){
                for(int k = j - 1; k >= 0; k--){
                    // 是单词首字符
                    // 1.句子第一个   2.句子中间
                    if((isalpha(res[i][k]) && k == 0) || (k >= 1 && res[i][k - 1] == ' ' && isalpha(res[i][k])) )  {
                        if(res[i][k] >= 'A' && res[i][k] <= 'Z') {
                            res[i][k] += 32;
                        }else if(res[i][k] <= 'z' && res[i][k] >= 'a'){
                            res[i][k] -=32;
                        }
                        break;
                    }
                    res[i][j] = '1';
                }
            }
        }
    }
    for(int i = 0; i < res.size(); i++){
        if(del.find(i) != del.end()) continue;
        for(int j = 0; j < res[i].size(); j++){
            if(!isdigit(res[i][j])){
                cout << res[i][j];
            }
        }
        cout << endl;
    }
    ifs.close();
    return 0;

}