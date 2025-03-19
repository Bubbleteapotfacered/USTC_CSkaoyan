#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> res;
    for(int i = 0; i < m; i++){
        int temp ;
        cin >> temp;
        nums1.push_back(temp);
    }
    for(int j = 0; j < n; j++){
        int temp ;
        cin >> temp;
        nums2.push_back(temp);
    }

    // 暴力
    int len = m + n;
    int count = 0;
    int index_1 = 0;
    int index_2 = 0;
    // 直接拼接在一起---归并
    while(count++ < len){
        if(index_1 >= m) {
            res.push_back(nums2[index_2++]);
        }else if(index_2 >= n){
            res.push_back(nums1[index_1++]);
        }else{
            if(nums1[index_1] < nums2[index_2]){
                res.push_back(nums1[index_1++]);
            }else{
                res.push_back(nums2[index_2++]);
            }
        }
    }
    if (len % 2 == 0) cout << res[len / 2 - 1] << " " << res[len / 2];
    else cout << res[len / 2];

    return 0;

}