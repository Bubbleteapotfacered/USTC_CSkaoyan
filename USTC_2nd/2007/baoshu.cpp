#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> que;
    for(int i = 1; i <= n; i++){
        que.push(i);
    }
    int flag = 1;
    while(!que.empty()){
        if(flag == 1){
            cout << que.front() << " ";
            que.pop();
            flag = 2;
        }else{
            que.push(que.front());
            que.pop();
            flag = 1;
        }
    }
    
}