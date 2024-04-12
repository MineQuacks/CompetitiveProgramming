#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;cin>>test;
    for(int t=0;t<test;t++)
    {
        int n;cin>>n;
        int arr[n];
        bool equal=true;
        cin>>arr[0];
        int number=arr[0];
        for(int i=1;i<n;i++)
        {
            cin>>arr[i];
            if(number!=arr[i])equal=false;
        }
        if(equal){
            cout<<-1<<endl;
            continue;
        }
        int dist=0;
        int mins=999999999;
        /*for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[n-1])break;
            dist++;
        }
        mins = dist;
        dist = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]!=arr[0])break;
            dist++;
        }*/
        dist = 1;
        for(int i=1;i<n+1;i++)
        {
            if(i!=n && arr[i-1]==arr[i])
            {
                dist++;
            }else
            {
                if((i-dist-2>=0 &&arr[i-dist-1]!=arr[i-dist-2]) || (i<=n-2 && arr[i+1]!=arr[i]) || i-dist-1==0 || i==n)
                {
                    mins = min(mins,dist);
                }
                
                dist=1;
                
            }
        }
        cout<<mins<<endl;
    }
}