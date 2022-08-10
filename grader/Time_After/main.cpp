#include <iostream>

using namespace std;

int main()
{
    int hour,minute;
    int time;
    cin >> hour >> minute;
    cin >> time;
    int hourAns = hour + time / 60 ;
    int minuteAns = minute + time%60;
    while(minuteAns >= 60){
        hourAns++;
        minuteAns-=60;
    }
    hourAns%=24;
    if(hourAns < 10){
        cout << "0" << hourAns << " ";
    } else{
        cout << hourAns << " ";
    }
    if(minuteAns < 10){
        cout << "0" << minuteAns << " ";
    } else{
        cout << minuteAns << " ";
    }
}
