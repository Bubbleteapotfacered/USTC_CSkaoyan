#include<bits/stdc++.h>

using namespace std;

bool isop(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}
int calculate(char c, int num1, int num2){
    if(c == '+') return num1 + num2;
    else if(c == '-') return num1 - num2;
    else if(c == '*') return num1 * num2;
    else if(c == '/') return num1 / num2;
    return 0;
}

int main(){
    ifstream ifs("pre.in");
    string s;
    stack<int> st;
    vector<string> formula;
    while(ifs >> s){
        // 可能是两位及以上数字, 使用string先存放
        formula.push_back(s);
    }
    for(int i = formula.size() - 1; i >= 0; i--){
        // 逆序遍历前缀表达式
        // 是符号---计算
        if(isop(formula[i][0])){
            // 先出栈的元素靠前
            int num1 = st.top();st.pop();
            int num2 = st.top();st.pop();
            st.push(calculate(formula[i][0], num1, num2));
        }else{
            // 是数字, 入栈
            st.push(stoi(formula[i]));
        }
    }
    cout << st.top();
    ifs.close();
}