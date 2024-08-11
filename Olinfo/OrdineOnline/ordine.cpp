#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define INF LLONG_MAX
#define MAX 100001
ifstream fin ("input.txt");
ofstream fout ("output.txt");
ll n;
vector<vector<int>>canTake(3,vector<int>(MAX));
vector<ll>lastCanTake(MAX);
ll dp(int x,int col,ll first)
{
    bool cambiaFirst=false;
    ll newFirst=first;
    if(first==-1)cambiaFirst=true;
    if(col==2)return 0;
    ll res=0;
    ll localCanTake;
    if(x==-1)localCanTake = n;
    else localCanTake=canTake[col][x];
    if(col==1)localCanTake=min(localCanTake,lastCanTake[first]);
    for(int i=localCanTake-1;i>=0;i--){
        if(i==localCanTake-1 || canTake[col+1][i]!=canTake[col+1][i+1] || canTake[col+1][i+1]==0){
            if(canTake[col+1][i]==0)continue;
            if(cambiaFirst)newFirst=i;
            res=max(res,dp(i,col+1,newFirst)+i+1);
            if (x==2)cout<<i<<endl;
        }
    }
    if(canTake[col+1][0] != n)res=max(res,dp(-1,col+1,first));
    cout<<"x: "<<x<<" col:"<<col<<" res: "<<res<<" first: "<<first<<endl;
    return res;
} 

int conta(int N, vector<int> &A, vector<int> &P, vector<int> &D)
{
    n=N;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            canTake[i][j]=N;
        }
    }
    unordered_map<int,vector<int>> SetA;
    unordered_map<int,vector<int>> SetB;
    for(int i=0;i<N;i++){
        SetA[A[i]].push_back(i);
        SetB[P[i]].push_back(i);
    }
    //seleziona can take fila A
    unordered_set<int>presi;
    for(int i=0;i<N;i++){
        int p = P[i];
        if(SetA.count(p)){
            for(int u:SetA[p]) canTake[0][u]=N-i;
        }
    }
    presi.insert(P[0]);
    for(int i=1;i<N;i++){
        if(presi.count(P[i]))canTake[0][i]=0;
        presi.insert(P[i]);
        canTake[0][i]=min(canTake[0][i],canTake[0][i-1]);
    }
    //seleziona can take fila B
    for(int i=0;i<N;i++){
        int p = D[i];
        if(SetB.count(p)){
            for(int u:SetB[p]) canTake[1][u]=N-i;
        }
    }
    presi.clear();
    presi.insert(D[0]);
    for(int i=1;i<N;i++){
        if(presi.count(D[i]))canTake[1][i]=0;
        presi.insert(D[i]);
        canTake[1][i]=min(canTake[1][i],canTake[1][i-1]);
    }
     //seleziona can take fila A-C
    presi.clear();
    for(int i=0;i<N;i++){
        int p = D[i];
        if(SetA.count(p)){
            for(int u:SetA[p]) lastCanTake[u]=N-i;
        }
    }
    for(int i=1;i<N;i++){
        if(presi.count(D[i]))lastCanTake[i]=0;
        presi.insert(D[i]);
        lastCanTake[i]=min(lastCanTake[i],lastCanTake[i-i]);
    }
    cout<<canTake[1][3]<<endl;
    for(int i=0;i<N;i++)canTake[2][i]=i;
    return dp(-1,-1,-1);
}

#ifndef EVAL
int main()
{
    fin>>n;
    vector<int>A,B,C;
    for(int i=0;i<n;i++){
        int a;fin>>a;A.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;fin>>a;B.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;fin>>a;C.push_back(a);
    }
    fout<<conta(n,A,B,C);

}
#endif