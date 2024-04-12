#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>memo (1001,vector<int>(100001,-1));
vector<ll>W;
vector<ll>P;
ll solve(ll x,ll k)
{
    if(k<0)return -10000000;
    if(x<0)return 0;
    ll res1=0,res2=0;
    if(memo[x][k]!=-1)return memo[x][k];
    res1 = solve(x-1,k);
    res2 = solve(x-1,k-W[x])+P[x];
    memo[x][k]=max(res1,res2);
    return memo[x][k];
}
int main()
{
    ll n,k;cin>>n>>k;
    W.resize(n);
    P.resize(n);
    for(int i=0;i<n;i++)cin>>W[i];
    for(int i=0;i<n;i++)cin>>P[i];
    cout<<solve(n-1,k);
}