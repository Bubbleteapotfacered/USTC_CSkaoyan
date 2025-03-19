#include<bits/stdc++.h>
using namespace std;

int op_level(char c){
    // 运算符的优先级
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    // 括号
    return 0;
}

int main(){
    ifstream ifs("expr.in");
    ofstream ofs("expr.out");
    string s;
    ifs >> s;
    // 用来存放还未确定的运算符
    stack<char> op;
    for(int i = 0; i < s.size(); i++){
        // 如果是运算值的话,直接输出
        if(isalpha(s[i])) ofs << s[i];
        // 是括号或者运算符
        else{
            // 栈空直接入栈
            // 左括号直接入栈
            if(s[i] == '(' || op.empty()) op.push(s[i]);
            else if(s[i] != ')' && op_level(op.top()) < op_level(s[i])){
                // 如果不是右括号，而且栈顶元素优先级小于当前元素，入栈
                op.push(s[i]);
            }else if(s[i] != ')' && op_level(op.top()) >= op_level(s[i])){
                // 如果不是右括号，而且栈顶元素优先级大于等于当前元素，持续出栈
                while(!op.empty() && op_level(op.top()) >= op_level(s[i])){
                    ofs << op.top(); op.pop();
                }
                // 弹出后加入这次的运算符
                op.push(s[i]);
            }else {
                // 将括号内剩下的都输出
                while(op.top() != '('){
                    ofs<< op.top(); op.pop();
                }
                // 出左括号
                op.pop();
            }
        }
    }
    while(!op.empty()){
        // 剩下的运算符全部弹出
        ofs << op.top(); op.pop();
    }

    
    ifs.close();
    ofs.close();
}