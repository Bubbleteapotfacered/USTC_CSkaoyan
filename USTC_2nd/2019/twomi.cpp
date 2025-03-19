#include<bits/stdc++.h>

using namespace std;

int main(){

    int num;
    cin >> num;
    int num_copy = num;
    // 用来记录位数  从低位开始
    int count = 0;
    vector<int> res;
    // 除二取余法 先求的是低位
    while(num > 0){
        if(num % 2 == 1) {
            // 将二进制位是1的 记录下来
            // count表示从低往高第几位   即权重
            res.push_back(count);
        }
        count++;
        num /= 2;
    }

    if(res.size() == 2){
        // 二进制有2个1
        printf("%d = 2^%d + 2^%d", num_copy, res[0], res[1]);
    }else {
        cout << "NO";
    }

}