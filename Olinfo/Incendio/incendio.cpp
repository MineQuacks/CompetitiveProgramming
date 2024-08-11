#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long 
#define MAXN 1000000001

int n;
vector<vector<int>> distanze;
vector<vector<bool>> visited;
int currRes=90000;

void dfs(int x,int y, int limit)
{
    if(x==-1 || y==-1 || x==n || y==n)return;
    if(visited[x][y])return;
    visited[x][y]=true;
    if(distanze[x][y]<limit)return;
    if(x==n-1 && y==n-1)currRes=limit;
    dfs(x+1,y,limit);
    dfs(x-1,y,limit);
    dfs(x,y+1,limit);
    dfs(x,y-1,limit);
}

int alzati(int N, int M, int X[], int Y[])
{
    n=N;
    distanze.resize(N,vector<int>(N,MAXN));
    visited.resize(N,vector<bool>(N));
    queue<pair<int,int>>q;
    for(int i=0;i<M;i++){
        q.push({X[i],Y[i]});
        distanze[X[i]][Y[i]]=0;
    }
    vector<pair<int,int>>directions = {{0,-1},{0,+1},{-1,0},{+1,0}};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        //cout<<x<<" "<<y<<endl;
        q.pop();
        if(visited[x][y])continue;
        visited[x][y]=true;
        for(pair<int,int> u: directions){
            if(x+u.first == -1 || x+u.first == N || y+u.second == -1 || y+u.second == N)continue;
            if(distanze[x+u.first][y+u.second] > distanze[x][y]+1)
            {
                distanze[x+u.first][y+u.second] = distanze[x][y]+1;
                q.push({x+u.first,y+u.second});
            }
        }
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cout<<distanze[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int maxDist=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            maxDist=max(maxDist,distanze[i][j]);
        }
    }
    for(int i=maxDist;i>=0;i--)
    {
        visited.clear();
        visited.resize(N,vector<bool>(N));
        dfs(0,0,i);
        if(currRes==i)break;
    }
    return currRes-1;
}

#ifndef EVAL
int main()
{
    int N,M;fin>>N>>M;
    int X[M],Y[M];
    for(int i=0;i<M;i++)fin>>X[i]>>Y[i];
    fout<<alzati(N,M,X,Y);
}
#endif
