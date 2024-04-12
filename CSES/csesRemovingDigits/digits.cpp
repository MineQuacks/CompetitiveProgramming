#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000+1
using namespace std;
vector<ll>memo(MAX);

ll solve(int x)
{
    if(x==0)return 0;
    string xstr = to_string(x);
    if(memo[x]==MAX)
    {
        for(char c:xstr)
        {
            memo[x]=min(memo[x],solve(x-(c-'0'))+1);
        }
    }
    return memo[x];
}



int main()
{
    ll n;cin>>n;
    for(int i=0;i<memo.size();i++)memo[i]=MAX;  
    cout<<solve(n);
    
}