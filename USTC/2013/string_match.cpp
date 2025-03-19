#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream ifs("6.in");
    ofstream ofs("6.out");
    
    string s1, s2;
    ifs >> s1 >> s2;

    cout << s1 << endl << s2;
    
    for(int i = 0; i < s1.size(); i++){
        int count = 0;
        int index = i;
        for(int j = 0; j < s2.size(); j++){
            if(s1[index++] == s2[j]) count++;
        }
        if(count == s2.size()) {
            // 找到了
            ofs << i + 1 << " " << i + count;
            ofs.close();
            ifs.close();
            return 0;
        }
    }
    ofs << 0;

    ofs.close();
    ifs.close();
    
}