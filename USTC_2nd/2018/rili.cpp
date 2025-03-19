#include<bits/stdc++.h>

using namespace std;

int year_calendar[4] = {366,365,365,365};
int month_calendar[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
string dayname[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main(){
    int n, year = 2000, month = 1, date = 1;
    cin >> n;
    int index = 0;
    // 计算周几
    string day = dayname[n % 7];
    // 计算年份
    while(n >= year_calendar[index % 4]){
        n -= year_calendar[index++ % 4];
        year++;
    }
    index = 0;
    // 如果是闰年 2月为29天
    if(year % 4 == 0) month_calendar[1] = 29;
    // 计算月份
    while(n >= month_calendar[index]){
        n -= month_calendar[index++];
        month++;
    }
    date += n;
    printf("%d-%d-%d ", year, month, date);
    cout << day;
}