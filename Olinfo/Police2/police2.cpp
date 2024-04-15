#include <bits/stdc++.h>
using namespace std;
vector<int>nexts;
vector<bool>visited;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int island;
map<int,int>visitList;
int loopSize;
void dfs(int x)
{
    if(visited[x]){
        if(visitList[x]==0)loopSize=0;
        else loopSize = island - visitList[x];
        return;
    }
    visited[x]=true;
    visitList[x]=island;
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
        if(visited[i])continue;
        visitList.clear();
        island=1;
        loopSize = 0;
        if(!visited[i])dfs(i);
        maxisland=max(loopSize,maxisland);  
    }
    fout<<maxisland;
}