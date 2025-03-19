#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("number.in");
    ofstream ofs("number.out");
    int n;
    ifs >> n;
    vector<int> nums;
    int num;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for(int i = 0; i < n; i++){
        ifs >> num;
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    int common;
    for(int i = 1; i <= min_val; i++){
        if(min_val % i == 0 && max_val % i == 0){
            common = i;
        }
    }
    


    ofs << min_val << " " << max_val << " " << common;
    // cout << min_val << " " << max_val << " " << common;
    ifs.close();
    ofs.close();

}