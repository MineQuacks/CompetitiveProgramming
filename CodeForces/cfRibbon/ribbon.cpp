#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;cin>>test;
    for(int t=0;t<test;t++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int div = n/m;
        if(n%m!=0)div++;
        if (k>=n-div)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
}