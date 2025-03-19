#include<bits/stdc++.h>

using namespace std;

int max_gongyue(int& num1, int& num2){
    int res = 1;
    for(int i = 1; i <= min(num1, num2); i++){
        if(num1 % i == 0 && num2 % i == 0) res = i;
    }
    return res;
}


int main(){
    ifstream ifs("number.in");
    ofstream ofs("number.out");
    int n;
    ifs >> n;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int num;
    for(int i = 1; i <= n; i++){
        ifs >> num;
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    
    
    ofs << min_val << " " << max_val << " " << max_gongyue(min_val, max_val);
    ifs.close();

}