#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for(int i = 1; i <= n; i++){
        que.push(i);
    }
    int count = 1;
    while(!que.empty()){
        if(count != m){
            que.push(que.front());
            que.pop();
            count++;
            continue;
        }else{
            cout << que.front() << " ";
            que.pop();
            count = 1;
        }
    }
    
    return 0;
}