#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int t=0;t<n;t++)
    {
        string time;cin>>time;
        int hour = (int(time[0])-48)*10 + int(time[1])-48;
        //cout<<"AAAAAAAAA "<<hour<<endl;
        string post="AM";
        if(hour>=12)post="PM";
        if(hour>=13)hour-=12;
        if(hour == 0)hour = 12;
        string hourPrint = "0";
        if (hour <=9)hourPrint+=to_string(hour);
        else hourPrint=to_string(hour);
        cout<<hourPrint<<":"<<time[3]<<time[4]<<" "<<post<<endl;
    }
}