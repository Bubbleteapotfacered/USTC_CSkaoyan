#include<bits/stdc++.h>

using namespace std;

int n = 5;
vector<char> path;
vector<vector<char>> res;
void backtracking(string& s, int start){
    if(path.size() == 5){
        res.push_back(path);
        return ;
    }
    for(int i = start; i < s.size(); i++){
        path.push_back(s[i]);
        backtracking(s, i + 1);
        path.pop_back();
    }
}
int main(){
    string s = "abcdefghij";

    backtracking(s, 0);
    
    for(int i = 0; i < res.size(); i++){
        printf("The %d th  ", i + 1);
        for(int j = 0; j < res[i].size(); j++){
            if(j != 0) cout << ",";
            cout << res[i][j];
        }
        cout << endl;
    }

}