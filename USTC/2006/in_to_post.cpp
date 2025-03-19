#include<bits/stdc++.h>
using namespace std;
#include<fstream>

int isop(char c){
    // 加减返回1
    if(c == '+' || c == '-') return 1;
    // 乘除返回2
    else if(c == '*' || c == '/') return 3;
    // 是括号
    else if(c == '(') return 0;
    else return 4;
}

int main(){
    ifstream ifs("expr.in");
    ofstream ofs("expr.out");
    string s;


    while(getline(ifs, s)){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            // 是运算值
            if(isalpha(s[i])) ofs << s[i];
            // 是运算符 或者  括号
            else{
                // 栈为空，运算符直接入栈
                if(st.empty()) st.push(s[i]);
                // 左括号直接入栈
                else if(s[i] == '(') st.push(s[i]);
    
                // s[i]不是右括号,而且前面优先级大于等于后面的，先算  比如2 * 8 + 5   2 + 8 + 5
                else if(s[i] != ')' && isop(st.top()) >= isop(s[i])){
                    // 这里得while出去
                    while(s[i] != ')' && !st.empty() &&isop(st.top()) >= isop(s[i])){
                        ofs << st.top();
                        st.pop();
    
                    }
                    // push这次的运算符
                    st.push(s[i]);
                }
                // s[i]不是右括号，而且前面优先级小，push，比如2 + 5 * 8   要push*  防止后面有括号
                else if(s[i] != ')' && isop(st.top()) < isop(s[i])){
                    st.push(s[i]);
                }
                // 如果是右括号，那么依次弹出来，而且顺序都是后面先于前面，因为前面大于等于后面的已经计算完毕了
                else if(s[i] == ')'){
                    // 右括号
                    while(!st.empty() && st.top() != '('){
                        ofs << st.top();
                        st.pop();
                    }
                    // 出左括号
                    st.pop();
                }
            }
        }
        // 剩下的全部弹出去
        while(!st.empty()){
            ofs << st.top();
            st.pop();
        }
        ofs << endl;
    }

    
    ofs.close();
    ifs.close();
}