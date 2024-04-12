#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
bool grid [1000][1000];
bool visited [1000][1000];
int n,m;
void dfs(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)return;
    if(visited[x][y])return;
    if(!grid[x][y])return;
    visited[x][y]=true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            if(c=='.')grid[i][j]=true;
            else grid[i][j]=false;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]){
                res++;
                dfs(i,j);
            }
        }
    }
    cout<<res;

}