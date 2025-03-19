#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& nums, int left, int right){
    // 找到pivot的位置


    if(left >= right) return -1;
    int pivot = nums[left];
    while(left < right){
        while(left < right && nums[right] >= pivot) right--;
        nums[left] = nums[right];
        while(left < right && nums[left] <= pivot) left++;
        nums[right] = nums[left];
    }
    
    nums[left] = pivot;
    return left;
}
void quickSort(vector<int>& nums, int left, int right, int k){
    int mid = partition(nums, left, right);
    if(mid == -1) return ;
    // 第k个位置的元素到位了, 返回
    if(mid == k) return;
    // k在mid右边
    else if(mid < k) quickSort(nums, mid + 1, right, k);
    // k在mid左边
    else quickSort(nums, left, mid - 1, k);
}
int main(){
    ifstream ifs("array.in");
    int n, k;
    ifs >> n >> k;

    // 快排写法
    vector<int> nums(n, 0);
    int num;
    for(int i = 0; i < n; i++){
        ifs >> num;
        nums[i] = num;
    }
    quickSort(nums, 0, n - 1, k - 1);

    cout << nums[k - 1];

    ifs.close();
    return 0;
}

