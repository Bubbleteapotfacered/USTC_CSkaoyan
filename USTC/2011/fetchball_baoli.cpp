#include<iostream>

#include<vector>

using namespace std;

int main(){
    int x, y, k;
    cin >> x >> y >> k;

    int count = 0;

    for(int i = 0; i <= 8 && i <= x; i++){
        for(int j = 0; j <= 8 - i && j <= y; j++){            

            if(8 - i - j <= k){
                    count++;
                    cout << i << "¸öºìÇò " << j << "¸ö»ÆÇò " << 8 - i - j << "¸öºÚÇò" << endl;
            }
        }
    }
    cout << count;
}