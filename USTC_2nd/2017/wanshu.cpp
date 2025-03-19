#include<bits/stdc++.h>

using namespace std;

void iswanhui(int num){

    int sqrt = 0;
    while(sqrt * sqrt <= num){
        sqrt++;
    }
    sqrt--;
    int sum = 1;
    for(int i = 2; i <= sqrt; i++){
        if(num % i == 0){
            sum += i;
            if(num / i != i) sum += num / i;
        }
    }
    if(sum > num) cout << "yingshu" << num << endl;
    else if(sum == num) cout << "wanshu" << num << endl;
}

int main(){
    for(int i = 2; i <= 1000; i++){
        iswanhui(i);
    }
    return 0;
}