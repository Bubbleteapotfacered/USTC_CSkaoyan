#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // n个人数到m出圈
    
    queue<int> que;
    for(int i = 1; i <= n; i++){
        que.push(i);
    }

    int total = 0;
    int count = 1;
    while(total < n){
        if(count == m){
            cout << que.front() << " ";
            que.pop();
            count = 1;
            total++;
        }else{
            int temp = que.front();
            que.pop();
            que.push(temp);
            count++;
        }
    }
    return 0;

}