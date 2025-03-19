#include<bits/stdc++.h>

using namespace std;

double calculate(double x){
    return 2 * pow(x, 11) - 3 * pow(x, 8) - 5 * pow(x, 3) - 1;
}


int main(){
    double left = 0, right = 2;
    while(right - left > 0.00000001){
        double mid = (left + right) / 2;
        // cout << mid << " ";
        if(calculate(mid) > 0) right = mid;
        else if(calculate(mid) < 0) left = mid;
        else break;
    }

    printf("%.8f", left);
}