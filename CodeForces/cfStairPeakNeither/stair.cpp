#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        if(a<b && b<c)cout<<"STAIR";
        else if(a<b && b>c)cout<<"PEAK";
        else cout<<"NONE";
        if(i!=n-1)cout<<"\n";
    }
}