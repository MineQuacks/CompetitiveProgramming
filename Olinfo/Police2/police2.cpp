#include <bits/stdc++.h>
using namespace std;
vector<int>nexts;
vector<bool>visited;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int island;
bool loop;
int first;
void dfs(int x)
{
    if(visited[x]){
        if(x==first)loop = true;
        return;
    }
    visited[x]=true;
    island++;
    dfs(nexts[x]);
}

int main()
{
    int n;fin>>n;
    nexts.resize(n);
    visited.resize(n);
    for(int i=0;i<n;i++)fin>>nexts[i];
    int maxisland = 0;
    for(int i=0;i<n;i++)
    {
        loop =false;
        first=i;
        for(int j=0;j<n;j++)visited[j]=false;
        island=0;
        dfs(i);
        if(loop)maxisland=max(island,maxisland);  
    }
    fout<<maxisland;
}