#include <bits/stdc++.h>
#define ll long long
using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector<ll>adj[10000];
vector<ll>visited(10000);
vector<ll>sticks(10000);
vector<ll>res;
ll nvisits;

void dfs(ll x) 
{
    res.push_back(x);
    visited[x]=true;
    nvisits++;
    for(auto u:adj[x])
    {
        if(visited[u])continue;
        sticks[u]--;
        if(sticks[u]==0)dfs(u);
    }
}


int main()
{
    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        ll n,m;fin>>n>>m;
        for(int i=0;i<n;i++){adj[i].clear();sticks[i]=0;visited[i]=false;}
        res.clear();
        nvisits=0;
        for(int i=0;i<m;i++)
        {
            ll a,b;fin>>a>>b;
            sticks[b]++;
            adj[a].push_back(b);
        }
        ll node=0;
        while(nvisits != n)
        {
            if(node>=n)node = 0;
            if(!visited[node] && sticks[node] ==0)dfs(node);
            node++;
        }
        fout<<"Case #"<<t<<": ";
        for(ll xxx:res)fout<<xxx<<" ";
        fout<<endl;

    }


}