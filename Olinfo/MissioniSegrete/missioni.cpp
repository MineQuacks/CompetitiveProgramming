#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<vector<int>>memo;
vector<int>T;
vector<int>D;
int dp(int x,int o){

    int m1=-1,m2=-1;
    if(x>=T.size())return 0;
    if(o>=365)return 0;
    if(memo[o][x]!=-1)return memo[o][x];
    //prendi
    if(o<=D[x]-T[x])m1=dp(x+1,o+T[x])+1;
    //no prendi
    m2=dp(x+1,o);
    memo[o][x]=max(m1,m2);
    return memo[o][x];
}

int main(){
    int n;fin>>n;
    T.resize(n);
    D.resize(n);
    memo.resize(365);
    for(int i=0;i<365;i++)memo[i].resize(n,-1);
    for(int i=0;i<n;i++){
        fin>>T[i]>>D[i];
    }
    fout<<dp(0,0);
}