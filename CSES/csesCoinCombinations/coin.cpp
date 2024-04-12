#include <bits/stdc++.h>
#define ll long long
#define MAX 1000001
using namespace std;
vector<ll>V;
vector<ll>memo;
ll n;
 
ll solve(ll x,ll last)
{
    if(x==0)return 1;
    if(x<0)return 0;
    if(memo[x]==-1)
    {
        memo[x]=0;
        ll lastVal=V[last];
        for(ll s=0;s<n;s++)
        {
            if(V[s]<=lastVal)memo[x]+=solve(x-V[s],s);
        }
        memo[x]%=1000000007;
    }
    return memo[x];
}
 
 
int main()
{
    ll k;
    cin>>n>>k;
    V.resize(n+1);
    memo.resize(k+1,-1);
    V[n]=MAX;
    for(int i=0;i<n;i++)cin>>V[i];
    cout<<solve(k,n)<<endl;
}