#include<iostream>
#include<vector>

using namespace std;

int main(){
    // 十进制转八进制
    int num;
    cin >> num;

    vector<int> res;
    while(num > 0){
        res.push_back(num % 8);
        num /= 8;
    }
    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i];
    }
    return 0;

}