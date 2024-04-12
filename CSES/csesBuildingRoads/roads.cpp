#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<ll>adj[100000];
vector<bool>visited(100000);
void dfs(ll x)
{
    visited[x]=true;
    for(auto r:adj[x])
    {
        if(!visited[r])dfs(r);
    }
}

int main()
{
    ll n,m;
    fin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;fin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll>res;
    ll s=0;
    for(ll i=1;i<n;i++)
    {
        if(!visited[i]){
            dfs(i);
            s++;
            res.push_back(i);
        }
    }
    cout<<s-1<<endl;
    for(ll r:res)cout<<r<<" ";
}