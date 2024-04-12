#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
char adj[MAXN][MAXN];
pair<bool,bool> visited[MAXN][MAXN];
int r,c;
char backslash = 92;
void dfs(int x, int y,bool ri){
    if (ri && visited[x][y].second)return;
    if (!ri && visited[x][y].first)return;
    if(ri)visited[x][y].second = true;
    else visited[x][y].first = true;
    //giu
    if(x<r-1){
        if(!ri && adj[x][y]=='/' || ri && adj[x][y]==backslash){}
        else{
            if(adj[x+1][y]=='/')dfs(x+1,y,false);
            if(adj[x+1][y]==backslash)dfs(x+1,y,true);
        }      
    }
    //su
    if(x>0){
        if(ri && adj[x][y]=='/' || !ri && adj[x][y]==backslash){}
        else{
            if(adj[x-1][y]=='/')dfs(x-1,y,true);
            if(adj[x-1][y]==backslash)dfs(x-1,y,false);
        }
    }
    //destra
    if(y<c-1 && ri){
        dfs(x,y+1,false);
    }
    //sinistra
    if(y>0 && !ri){
        dfs(x,y-1,true);
    }
}

int main(){
    
    fin>>r>>c;
    string row;
    for(int i=0;i<r;i++){
        fin>>row;
        for(int j=0;j<row.size();j++)
        {
            adj[i][j]=row[j];
        }
    }
    int islands=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!visited[i][j].first){
                islands++;
                dfs(i,j,false);
            }
            if(!visited[i][j].second){
                islands++;
                dfs(i,j,true);
            }
        }
    }
    fout<<islands;


}