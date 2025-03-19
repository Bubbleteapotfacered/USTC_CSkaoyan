#include<bits/stdc++.h>

using namespace std;

int main(){
    int i = 0;
    int sum = 0;
    while(i++ < 10){
        int num1 = rand() % 51;
        int num2 = rand() % 51;
        char c;
        if(rand() % 2 == 1) c = '+';
        else c = '-';
        int ans = 0; 
        if(c == '+') ans = num1 + num2;
        else ans = num1 - num2;

        cout << num1 << c << num2 << "=?"<<endl;
        for(int i = 0; i < 2; i++){
            int input;
            cin >> input;
            if(input == ans){
                if(i == 0) sum += 10;
                else sum += 5;
                break;
            }
            if(input != ans && i == 0){
                cout << "error, try again" << endl;
            }
        }

    }
    cout << "Your socre is" << sum;

}