#include <bits/stdc++.h>
#define MAXN 10000
#define INF 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2
using namespace std;
vector<int> dist(MAXN);
vector<pair<int,int>>adj[MAXN];
vector<bool> visited(MAXN);
priority_queue<pair<int,int>> pq;
void dijkstra(int x)
{
    for(int i=0;i<dist.size();i++)dist[i]=INF;
    dist[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int a=pq.top().second;
        pq.pop();
        if(visited[a])continue;
        visited[a]=true;       
        for(auto u : adj[a]){
            int b = u.first;
            int w = u.second;
            if(dist[a]+w < dist[b]){
                dist[b]=dist[a]+w;
                pq.push({-dist[b],b});
            }
        }
    }
}


int main()
{

}