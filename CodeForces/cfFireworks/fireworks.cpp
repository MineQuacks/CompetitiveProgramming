#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    int t;cin>>t;
    for(int test=0;test<t;test++)
    {
        ll a,b,w;cin>>a>>b>>w;
        if(b>a)swap(a,b);
        ll start2 = a-b;
        ll res= (w+1)/b  + (w-start2+1)/a;
        res+=2;
        if(w%a==0)res--;
        if((w-start2)%b==0)res--;
        cout<<res<<endl;

    }
}