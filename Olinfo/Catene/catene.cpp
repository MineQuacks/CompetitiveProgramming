#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long
#define MAXN 10000000

vector<pair<ll,ll>>adj[MAXN];
vector<bool>visited[2];
vector<ll>memo[2];
//0=no tp
//1=tp

ll dp(ll x,bool arrivatoConTp,ll nodeFrom)
{
    if(memo[arrivatoConTp][x]!= -1)return memo[arrivatoConTp][x];
    ll c1=0,c2=0,c3=0,c4=0;
    ll allTps=0;
    for(int i=0;i<adj[x].size();i++){
        if(adj[x][i].first==nodeFrom)continue;
        allTps+=dp(adj[x][i].first,true,x);
    }
    //c1: catena comincia qui (da padre a figlio)
    for(int i=0;i<adj[x].size();i++){
        if(adj[x][i].first==nodeFrom)continue;
        c1=max(c1,dp(adj[x][i].first,false,x)+allTps-dp(adj[x][i].first,true,x) + adj[x][i].second);
    }
    //c2:  catena finisce qui
    c2=allTps;
    //c3: da figlio a figlio
    if(arrivatoConTp){
        ll firstBestNode=-1;
        ll firstBestValue=-1;
        ll secondBestNode=-1;
        ll secondBestValue=-1;
        for(int i=0;i<adj[x].size();i++){
            if(adj[x][i].first==nodeFrom)continue;
            ll newVal=dp(adj[x][i].first,false,x) + adj[x][i].second -dp(adj[x][i].first,true,x);
            if(newVal>=firstBestValue){
                secondBestValue=firstBestValue;
                secondBestNode=firstBestNode;
                firstBestValue=newVal;
                firstBestNode=i;
            }else if(newVal>secondBestValue){
                secondBestNode=i;
                secondBestValue=newVal;
            }
        }
        c3=firstBestValue+secondBestValue+allTps;
    }
    //cout<<"x: "<<x+1<<" tp:"<<arrivatoConTp<<" c1: "<<c1<<" c2: "<<c2<<" c3: "<<c3<<" c4:"<<c4<<endl;
    memo[arrivatoConTp][x]=max(max(c1,c2),max(c3,c4));
    return memo[arrivatoConTp][x];
}

long long profitto_massimo(int N, int U[], int V[], int W[])
{
    visited[0].resize(N);
    visited[1].resize(N);
    memo[0].resize(N,-1);
    memo[1].resize(N,-1);
    for(int i=0;i<N-1;i++)
    {
        if(W[i]<0)W[i]=0;
        adj[U[i]-1].push_back({V[i]-1,W[i]});
        adj[V[i]-1].push_back({U[i]-1,W[i]});
    }
    ll soluzione=0;
    soluzione=dp(0,true,-1);
    return soluzione;
}

#ifndef EVAL
int main()
{
    int N;fin>>N;
    int U[N-1],V[N-1],W[N-1];
    for(int i=0;i<N-1;i++)
    {
        fin>>U[i]>>V[i]>>W[i];
    }
    cout<<profitto_massimo(N,U,V,W)<<endl;
    for(int i=0;i<memo[0].size();i++){
        cout<<i+1<<": "<<max(memo[0][i],memo[1][i])<<endl;
    }
}
#endif