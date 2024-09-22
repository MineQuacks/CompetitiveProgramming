#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long
#define INF 100000000000000000
int N,K;
vector<ll>S;
vector<vector<ll>>memo[4];

ll dp(int x,int k,int lanci)
{
    if(lanci==0){
        k++;
        lanci=3;
    }
    if(k>K)return 0;
    if(memo[lanci][x][k]!=-INF)return memo[lanci][x][k];    
    ll res=-INF;
    for(int i=2;i<=12;i++){
        ll val=-INF;
        if(i!=2 && i!=12)val=dp((x+i)%N,k,0)+S[(x+i)%N];
        if(i%2==0)val=max(val,dp((x+i)%N,k,lanci-1)+S[(x+i)%N]);
        
        res=max(res,val);
    }
    //cout<<"x: "<<x<<endl<<"k: "<<k<<endl<<"lanci: "<<lanci<<endl<<"res: "<<res<<endl<<endl;
    memo[lanci][x][k] = res;
    return res;
}


int main()
{
    fin>>N>>K;
    S.resize(N);
    for(int i=0;i<N;i++)fin>>S[i];
    for(int i=0;i<=3;i++)memo[i].resize(N,vector<ll>(K+1,-INF));
    cout<<dp(0,1,3);
}