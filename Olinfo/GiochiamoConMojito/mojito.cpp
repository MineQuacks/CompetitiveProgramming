#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<int>adj(100);
vector<bool>visited(100);
int res=0;
void dfs(int x){
    if(visited[x])return;
    res++;
    visited[x]=true;
    dfs(adj[x]);
}

int main(){
    int righe,col;
    fin>>righe>>col;
    pair<int,int>start;
    int a,b;fin>>a>>b;
    a--;b--;
    start = {a,b};
    int n;fin>>n;
    int c,d;
    vector<pair<int,int>>ragazzi;
    vector<pair<int,int>>tiri;
    for(int i=0;i<n;i++){
        fin>>a>>b>>c>>d;
        ragazzi.push_back({a-1,b-1});
        tiri.push_back({c-1,d-1});
    }
    
    for(int i=0;i<n;i++){
        int ragazzoPiuVicino=0;
        int distVicino=1000;
        pair<int,int>CoordsVicino;
        pair<int,int>tiro = tiri[i];
        for(int j=0;j<n;j++)
        {
            pair<int,int>ragazzo= ragazzi[j];
            int distanza = 0;
            distanza += abs(tiro.first - ragazzo.first) + abs(tiro.second - ragazzo.second);
            if(distanza<distVicino){
                distVicino=distanza;
                ragazzoPiuVicino=j;
                CoordsVicino = ragazzo;
            }
            if(distanza == distVicino){
                if(ragazzo.first < CoordsVicino.first){
                    distVicino=distanza;
                    ragazzoPiuVicino=j;
                    CoordsVicino = ragazzo;
                }
                if(ragazzo.first == CoordsVicino.first && ragazzo.second < CoordsVicino.second){
                    distVicino=distanza;
                    ragazzoPiuVicino=j;
                    CoordsVicino = ragazzo; 
                }
            }
        }
        adj[i]=ragazzoPiuVicino;
    }
    int primoRagazzo;
    int ragazzoPiuVicino=0;
    int distVicino=1000;
    pair<int,int>CoordsVicino;
    for(int j=0;j<n;j++)
    {
        pair<int,int>ragazzo= ragazzi[j];
        int distanza = 0;
        distanza += abs(start.first - ragazzo.first) + abs(start.second - ragazzo.second);
        if(distanza<distVicino){
            distVicino=distanza;
            ragazzoPiuVicino=j;
            CoordsVicino = ragazzo;
        }
        if(distanza == distVicino){
            if(ragazzo.first < CoordsVicino.first){
                distVicino=distanza;
                ragazzoPiuVicino=j;
                CoordsVicino = ragazzo;
            }
            if(ragazzo.first == CoordsVicino.first && ragazzo.second < CoordsVicino.second){
                distVicino=distanza;
                ragazzoPiuVicino=j;
                CoordsVicino = ragazzo; 
            }
        }
    }
    dfs(ragazzoPiuVicino);
    fout<<res;
}