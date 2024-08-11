#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define INF LLONG_MAX
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<pair<int,int>>adj[MAX];
priority_queue<pair<int,int>>pq;
vector<bool>visited;
vector<long long>dist;

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T)
{
    vector<pair<int,int>>candles(N);
    for(int i=0;i<N;i++)candles[i]={M[i],i};
    sort(candles.begin(),candles.end());
    dist.resize(N,INF);
    visited.resize(N);
    dist[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int a=pq.top().second; pq.pop();
        if(visited[a])continue;
        visited[a]=true;
        //cout<<a<<endl;
        if(M[a]<B[a]){
            for(int i=N-1;i>=0;i--){
                if(candles[i].first < M[a])break;
                if(candles[i].second!=a && candles[i].first>=M[a] && candles[i].first<=B[a]){
                    int w = abs(M[a]-candles[i].first);
                    if(dist[a]+w < dist[candles[i].second]){
                    dist[candles[i].second]=dist[a]+w;
                   // cout<<"w: "<<w<<" i: "<<i<<endl;
                    if(!visited[candles[i].second])pq.push({-dist[candles[i].second],candles[i].second});
                    }
                }
            }
        }
        else if(M[a]>B[a]){
            for(int i=0;i<N;i++){
                if(candles[i].first > M[a])break;
                if(candles[i].second!=a && candles[i].first<=M[a] && candles[i].first>=B[a]){
                    int w = abs(M[a]-candles[i].first);
                    if(dist[a]+w < dist[candles[i].second]){
                    dist[candles[i].second]=dist[a]+w;
                    if(!visited[candles[i].second])pq.push({-dist[candles[i].second],candles[i].second});
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        T[i]=dist[i];
        if(T[i]==INF)T[i]=-1;
    }
}

#ifndef EVAL
int main(){
    int n;fin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;i++)fin>>A[i]>>B[i];
    vector<long long>T(n);
    brucia(n,A,B,T);
    for(auto r : T)fout<<r<<" ";
}
#endif