#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int d = m ^ n;

    // cout  << d << endl;
    vector<int> res ;
    while(d > 0){
        // 先加入的是低位, 后加入的是高位
        res.push_back(d % 2);
        d /= 2;
    }
    for(int i = res.size() - 1; i >= 0; i--){
        // 高位先输出, 低位后输出
        cout << res[i];
    }
    
}