#include<bits/stdc++.h>
using namespace std;


// 比较类
// struct cmp{
//     bool operator()(string a, string b){
//         int len = max(a.size(), b.size());
//         for(int i = 0; i < len; i++){
//             while(a[i % a.size()] == b[i % b.size()]){ 
//                 i++;
//             }        
//             return a[i % a.size()] > b[i % b.size()];
//         }
//         return true;
//     }
// };

// 比较函数
bool cmp(string a, string b){
    int len = max(a.size(), b.size());
    for(int i = 0; i < len; i++){
        if(a[i % a.size()] == b[i % b.size()]){ 
            continue;
        }        
        return a[i % a.size()] > b[i % b.size()];
    }
    return true;
}

// string排序  聪明做法
int main(){
    ifstream ifs("number.in");
    string s;
    vector<string> nums;
    while(ifs >> s){
        nums.push_back(s);
    }

    // 匿名内部类
    // sort(nums.begin(), nums.end(), [](string a, string b){
    //     int len = max(a.size(), b.size());
    //     for(int i = 0; i < len; i++){
    //         while(a[i % a.size()] == b[i % b.size()]){ 
    //             i++;
    //         }        
    //         return a[i % a.size()] > b[i % b.size()];
    //     }
    //     return true;
    // });

    sort(nums.begin(), nums.end(), cmp);
    // sort(nums.begin(), nums.end(), cmp());

    for(string num : nums){
        cout << num;
    }
    ifs.close();
}