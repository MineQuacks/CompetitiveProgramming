#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 100001
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<ll>P,T,W;
ll n;
vector<ll>adj[MAXN];


ll calcullate(ll x)
{
    if(x!=0)W[x]+=T[x-1];
    for(auto u:adj[x])
    {
        W[x]+=calcullate(u);
    }
    return W[x];
}

ll solve(ll x){
    if(adj[x].empty())return 0;
    if(adj[x].size()==1)return solve(adj[x][0]);
    ll res=0;
    ll maxBranch=0;
    ll maxBowNode=0;
    for(ll u:adj[x]){
        res+=T[u-1];
        if(W[u]>maxBranch){
            maxBranch=W[u];
            maxBowNode=u;
        }
    }
    if(maxBowNode!=0)res-=T[maxBowNode-1];
    if(!adj[x].empty())res+=solve(maxBowNode);
    return res;
}

int main()
{
    fin>>n;
    P.resize(n+1);T.resize(n+1),W.resize(n+1,0);
    for(int i=0;i<n;i++)fin>>P[i];
    for(int i=0;i<n;i++)fin>>T[i];
    for(int i=0;i<n;i++){
        adj[P[i]].push_back(i+1);
    }
    calcullate(0);
    fout<<solve(0);
}