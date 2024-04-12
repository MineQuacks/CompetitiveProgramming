#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>memo(0);
ll n;
ll solve(ll x)
{
    if(x<0)return 0;
    if(x==0)return 1;
    if(memo[x]==0)
    {
        for(int i=1;i<=6;i++)
        {
            memo[x]+=solve(x-i);
            memo[x]%=1000000007;
        }
    }
    return memo[x];
}

int main()
{
    cin>>n;
    memo.resize(n+1,0);
    solve(n);
    cout<<memo[n]<<endl;
    
}