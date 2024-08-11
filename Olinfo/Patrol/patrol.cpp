#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define MAXN 100000
vector<int>adj[MAXN];

int main()
{
    int n,m,k;
    fin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b;
        fin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>>L(k);
    for(int i=0;i<k;i++)
    {
        int a;fin>>a;
        L[i].push_back(a);
    }
    int mcl = 420;
    vector<vector<bool>>guards(mcl,vector<bool>(n));




}