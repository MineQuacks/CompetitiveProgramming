#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
vector<int> dist(MAXN);
vector<int>adj[MAXN];
vector<bool> visited(MAXN);
queue<int> q;
void BFS(int x)
{
    visited[x]=true;
    dist[x]=0;
    q.push(x);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto u : adj[a]){
            if(visited[u])continue;
            q.push(u);
            visited[u]=true;
            dist[u]=dist[x]+1;
        }
    }
}


int main()
{

}