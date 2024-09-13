#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");
ll N,R,T,L;
vector<ll>X;
vector<vector<ll>>memo;

//x = semaforo, r=quanti skip rimasti
ll dp(ll x,ll r)
{
    if(x<0)return 0;
    if(memo[x][r]!=-1)return memo[x][r];
    ll w=X[x];
    if(x>0)w-=X[x-1];
    if(x>0)w+=dp(x-1,r);
    //non skippo
    ll tempoDaAspettare = 0;
    if(T==0)tempoDaAspettare=INF;
    else if((w/T)%2==1)tempoDaAspettare= T-w%T;
    ll val1 = w + tempoDaAspettare;

    //skippo
    ll val2=val1;
    if(r>0)val2= w + dp(x-1,r-1) - dp(x-1,r);
    memo[x][r]= min(val1,val2);
    return memo[x][r];
}


int main()
{
    fin>>N>>R>>T>>L;
    X.resize(N);
    for(ll i=0;i<N;i++)fin>>X[i];
    sort(X.begin(),X.end());
    memo.resize(X.size(),vector<ll>(R+1,-1));
    fout<<dp(X.size()-1,R)+(L-X[X.size()-1]);
    
    /*for(ll i=0;i<memo.size();i++){
        cout<<i<<":  ";
        for(ll j=0;j<memo[0].size();j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }*/
}