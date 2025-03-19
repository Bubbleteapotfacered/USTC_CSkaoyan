#include<bits/stdc++.h>
using namespace std;

int y_calendar[] = {366, 365, 365, 365};
int m_calendar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main(){
    int n;
    int year = 2000, month = 1, date = 1;
    cin >> n;
    int index = 0;
    string d = day[n % 7];
    while(n >= y_calendar[index % 4]){
        n -= y_calendar[index % 4];
        year++;
        index++;
    }
    // 此时year已经定下来了
    // 接下来求month
    // 如果是闰年的话，2月为29天
    if(year % 4 == 0) m_calendar[1] = 29;
    index = 0;
    while(n >= m_calendar[index]){
        n -= m_calendar[index];
        month++;
        index++;
    }
    // 此时月份month已经定下来
    date += n;
    // int year = 2000, month = 1, data = 1;
    cout << year << "-" << month << "-" << date << " " << d;
    return 0;
}