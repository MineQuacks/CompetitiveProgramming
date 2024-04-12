#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
char grid [1000][1000];
bool visited [1000][1000];
int n,m;
string path;
string res;
void dfs(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)return;
    if(visited[x][y])return;
    if(grid[x][y]=='#')return;
    if(grid[x][y]=='B' ){
        if(path.size()<res.size() || res == "")
        {
            res=path;
        }  
        return;     
    }
    visited[x][y]=true;
    path+='U';
    dfs(x-1,y);
    path[path.length()-1]='D';
    dfs(x+1,y);
    path[path.length()-1]='R';
    dfs(x,y+1);
    path[path.length()-1]='L';
    dfs(x,y-1);
    path.pop_back();
}

int main()
{
    cin>>n>>m;
    path="";
    pair<int,int>start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A')start={i,j};
        }
    }
    dfs(start.first,start.second);
    if(res=="")cout<<"NO";
    else{
        cout<<"YES"<<endl;
        cout<<res.size()<<endl;
        cout<<res;
    }
    
}