#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int l;
vector<int>adj[100000];
vector<bool>visited;
vector<int>dist;
vector<int>C;
priority_queue<pair<int,int>>pq;

void dijkstra(int x)
{
    dist[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(auto u:adj[a]){
            int b = u;
            int w = 1;
            if(C[(dist[a]+1)%l]==b)w++;
            if(dist[a]+ w < dist[b]){
                dist[b]=dist[a]+w;
                pq.push({-dist[b],b});
            }
        }
    }
}

int main()
{
    int n,m;
    fin>>n>>m>>l;
    visited.resize(n);
    dist.resize(n,300000);
    C.resize(l);
    for(int i=0;i<m;i++)
    {
        int a,b;
        fin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<l;i++)fin>>C[i];
    dijkstra(0);
    fout<<dist[n-1];

}