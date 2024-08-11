#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B) 
{
    vector<vector<ll>>adj(N+1);
    for(ll i=0;i<M;i++){
        for(ll u:B[i])adj[u].push_back(i);
        if(B[i].size()==0)B[i].push_back(N);
    }
    priority_queue<pair<ll,ll>> pq;
    vector<ll>dist(N+1);
    for(ll i=0;i<N+1;i++)dist[i]=LLONG_MAX;
    for(ll i=0;i<M;i++){
        if(B[i][0]==N){
            pq.push({-1,A[i]});
            dist[A[i]]=1;
        }
    }
    vector<bool>visited(N+1);
    while(!pq.empty()){
        ll a = pq.top().second;
        pq.pop();
        if (visited[a])continue;
        visited[a]=true;
        for(auto b:adj[a]){
            bool visitabile= true;
            ll w=1;
            for(ll p:B[b]){
                if(!visited[p]){
                    visitabile=false;
                    break;
                }
                if(p!=a)w+=dist[p];
            }
            if(!visitabile)continue;        
            if(dist[a]+w < dist[A[b]]){
                dist[A[b]] = dist[a]+w;
                pq.push({-dist[A[b]],A[b]});
            }       
        }
    }
    return dist[0];
}


#ifndef EVAL
int main()
{
    int n,m; fin>>n>>m;
    vector<int>A(m);
    vector<vector<int>>B(m);
    for(int i=0;i<m;i++){
        int a;fin>>a;
        A[i]=a;
        int w;fin>>w;
        for(int j=0;j<w;j++){
            fin>>a;
            B[i].push_back(a);
        }
    }
    fout<< smaltisci(n,m,A,B);
    
}
#endif