#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>P(0);

ll solve(ll i,ll sum1,ll sum2)
{
    if(i==P.size())return abs(sum1-sum2);
    ll res1,res2;
    res1 = solve(i+1,sum1+P[i],sum2);
    res2 = solve(i+1,sum1,sum2+P[i]);
    return min(res1,res2);
}

int main()
{
    ll n;cin>>n;  
    P.resize(n); 
    for(int i=0;i<n;i++)
    {
        cin>>P[i];
    }
    
    cout<<solve(0,0,0);
    return 0;
}