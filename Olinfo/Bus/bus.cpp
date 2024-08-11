#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 1000000
ifstream fin ("input.txt");
ofstream fout ("output.txt");




int pianifica(int N, int L, vector<vector<int>> F)
{
    //graph
    vector<int>adj[N];
    for(int i=0;i<L;i++){
        for(int j=0;j<F[i].size()-1;j++){
            for(int z=j+1;z<F[i].size();z++){
                adj[F[i][j]].push_back(F[i][z]);
            }
        }
    }
    //bfs
    queue<int>q;q.push(0);
    vector<bool>visited(N);
    vector<int>distance(N,MAXN);distance[0]=0;
    while(!q.empty())
    {
        int a=q.front();q.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(int i=0;i<adj[a].size();i++)
        {
            int u=adj[a][i];
            if(visited[u])continue;
            if(distance[u]>distance[a]+1){
                distance[u]=distance[a]+1;
                q.push(u);
            }
        }
    }
    if(distance[N-1]==MAXN)return -1;
    return distance[N-1]-1;
}

#ifndef EVAL
int main()
{
    int N,L;fin>>N>>L;
    vector<vector<int>>F(L);
    for(int i=0;i<L;i++)
    {
        int k;fin>>k;
        for(int j=0;j<k;j++)
        {
            int a;fin>>a;
            F[i].push_back(a);
        }
    }
    fout<<pianifica(N,L,F);
}
#endif