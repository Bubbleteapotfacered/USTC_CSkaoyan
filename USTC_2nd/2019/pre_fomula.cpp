#include<bits/stdc++.h>

using namespace std;

bool isop(char c){
    // 判断是不是运算符
    if(c == '+' || c == '*' || c == '/' || c == '-') return true;
    return false;
}
int calculate(int& num1, int& num2, char& op){
    // 根据运算符进行计算 并且返回结果
    if(op == '+') return num1 + num2;
    else if(op == '-') return num1 - num2;
    else if(op == '*') return num1 * num2;
    else if(op == '/') return num1 / num2;
    return 0;
}

int main(){
    ifstream ifs("pre.in");

    string s;

    getline(ifs, s);

    stack<int> nums;
    for(int i = s.size() - 1; i >= 0; i--){
        // 如果是运算符的话，取数出栈运算，结果入栈
        if(isop(s[i])){
            // 因为是从后往前遍历的，先出来的是num1
            int num1 = nums.top(); nums.pop();
            int num2 = nums.top(); nums.pop();
            nums.push(calculate(num1, num2, s[i]));
        }
        // 如果是数字，直接入栈
        else if(isdigit(s[i])) nums.push(s[i] - '0');
    }
    cout << nums.top();
    ifs.close();
}