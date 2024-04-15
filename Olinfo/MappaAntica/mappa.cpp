#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int n;
char adj[100][100];
int dist[100][100];
priority_queue<pair<int,pair<int,int>>>pq;
bool visited[100][100];

void dijkstra(int x,int y){
    dist[x][y]=0;
    pq.push({0,{x,y}});
    while(!pq.empty()){
        int a = pq.top().second.first;
        int b =pq.top().second.second;
        if(visited[a][b])continue;
        visited[a][b]=true;
        pq.pop();
        if(a>0 && adj[a-1][b]!= '+' && dist[a][b] +1 < dist[a-1][b]){
            dist[a-1][b]= dist[a][b]+1;
            pq.push({-dist[a-1][b],{a-1,b}});
        }
        if(a<n-1 && adj[a+1][b]!= '+' && dist[a][b] +1 < dist[a+1][b]){
            dist[a+1][b]= dist[a][b]+1;
            pq.push({-dist[a+1][b],{a+1,b}});
        }
        if(b>0 && adj[a][b-1]!= '+'&& dist[a][b] +1 < dist[a][b-1]){
            dist[a][b-1]= dist[a][b]+1;
            pq.push({-dist[a][b-1],{a,b-1}});
        }
        if(b<n-1 && adj[a][b+1]!= '+' && dist[a][b] +1 < dist[a][b+1]){
            dist[a][b+1]= dist[a][b]+1;
            pq.push({-dist[a][b+1],{a,b+1}});
        }
        //alto sinistra
        if(a>0 && b>0 && adj[a-1][b-1]!= '+' && dist[a][b] +1 < dist[a-1][b-1]){
            dist[a-1][b-1]= dist[a][b]+1;
            pq.push({-dist[a-1][b-1],{a-1,b-1}});
        }
        //alto destra
        if(a>0 && b<n-1 && adj[a-1][b+1]!= '+' && dist[a][b] +1 < dist[a-1][b+1]){
            dist[a-1][b+1]= dist[a][b]+1;
            pq.push({-dist[a-1][b+1],{a-1,b+1}});
        }
        //basso destra
        if(a<n-1 && b<n-1 && adj[a+1][b+1]!= '+'&& dist[a][b] +1 < dist[a+1][b+1]){
            dist[a+1][b+1]= dist[a][b]+1;
            pq.push({-dist[a+1][b+1],{a+1,b+1}});
        }
        //basso sinistra
        if(a<n-1 && b>0 && adj[a+1][b-1]!= '+'&& dist[a][b] +1 < dist[a+1][b-1]){
            dist[a+1][b-1]= dist[a][b]+1;
            pq.push({-dist[a+1][b-1],{a+1,b-1}});
        }
    }
}


int main()
{
    fin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=10000;
        } 
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fin>>adj[i][j];
        }
    }
    dijkstra(0,0);
    fout<<dist[n-1][n-1]+1;
}