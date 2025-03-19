#include<iostream>
#include<vector>

using namespace std;

vector<char> path;

vector<vector<char>> res;

void backtracking(int start, string& s){
    if(path.size() == 5){
        res.push_back(path);
        return ;
    }
    for(int i = start; i < s.size(); i++){
        path.push_back(s[i]);
        backtracking(i + 1, s);
        path.pop_back();
    }
}

int main(){
    string s = "abcdefghij";
    backtracking(0, s);
    for(int i = 0; i < res.size();i++){
        cout << "The " << i + 1 << " Combination: ";
        for(int j = 0; j < res[j].size(); j++){
            
            if( j == 0 ) cout <<  res[i][j];
            else cout << "," << res[i][j];
        }
        cout << endl;
    }
    return 0;


}