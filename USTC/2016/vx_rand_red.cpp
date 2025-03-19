#include<bits/stdc++.h>

using namespace std;

int main(){
    // 记录已经分发的个数
    int count = 0;
    int all, n;
    cin >> all >> n;

    all = all * 100;

    while(count < n - 1){
        int val = rand() % all;
        while (!(val <= all - (n - count) * 1) || val == 0)
        {
            val = rand() % all;

        }
        all -= val;
        count ++;
        cout << val * 1.0 / 100 << " ";
        
    }

    
    cout << all * 1.0 / 100;

    

    

    

}