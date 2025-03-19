#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("input.txt");
    vector<string> article;
    string s;
    while(getline(ifs, s)){
        article.push_back(s);
    }
    unordered_set<int> del;
    for(int i = 0; i < article.size(); i++){
        for(int j = 0; j < article[i].size(); j++){
            // 如果是! 删除前一个字符
            if(article[i][j] == '!' && j > 0) article[i][j - 1] = '1';
            // 如果是*删除前面一行字符串
            if(article[i][j] == '*') del.insert(i - 1);
            // 如果是> 将前面一个单词的首字符进行大小写转换
            if(article[i][j] == '>'){
                for(int k = j - 1; k > 0; k--){
                    if(article[i][k] <= 'z' && article[i][k] >= 'a' && article[i][k-1] == ' ') {
                        article[i][k] -= 32;
                        break;
                    }else if(article[i][k] <= 'Z' && article[i][k] >= 'A' && article[i][k-1] == ' '){
                        article[i][k] += 32;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < article.size(); i++){
        if(del.find(i) != del.end()) continue;
        else{
            for(int j = 0; j < article[i].size(); j++){
                if(isalpha(article[i][j]) || article[i][j] == ' ') cout << article[i][j];
            }
        }
        cout << endl;
    }
}