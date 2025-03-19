#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int count = 0;
    int flag = 1;
    queue<int> que;
    for(int i = 1; i <= n; i++){
        que.push(i);
    }
    while(count < n){
        if(flag == 1){
            flag = 2;
            cout << que.front() << " ";
            que.pop();
            count++;
        }else{
            flag = 1;
            int temp = que.front();
            que.pop();
            que.push(temp);
        }
    }
    
}