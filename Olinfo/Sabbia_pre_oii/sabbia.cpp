#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long

struct fenTree{
    vector<ll>ft;

    ll LSB(ll x){return x & (-x);}

    void Update(ll x,ll val){
        x++;
        while(x<ft.size()){
            ft[x]+=val;
            x+=LSB(x);
        }
    }
    ll Sum(ll x){
        x++;
        ll sum=0;
        while(x>0){
            sum+=ft[x];
            x-=LSB(x);
        }
        return sum;
    }
    ll RangeSum(ll l,ll r){
        return(Sum(r)- Sum(l-1));
    }
    fenTree(vector<ll>origArray )
    {
        ft.resize(origArray.size()+1);
        for(ll i=0;i<origArray.size();i++)
        {
            Update(i,origArray[i]);
        }
    }

};





long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K)
{
    vector<ll>prefSum(N);
    prefSum[0]=V[0];
    for(ll i=1;i<N;i++)prefSum[i]=prefSum[i-1]+V[i];
    vector<ll>platNeeds(M);
    for(ll i=0;i<M;i++){
        if(L[i]>0)platNeeds[i]= prefSum[R[i]]-prefSum[L[i]-1] - K[i];
        else platNeeds[i]= prefSum[R[i]]- K[i];
        if(platNeeds[i]<0)platNeeds[i]=0;
    }
    vector<pair<pair<ll,ll>,ll>>plats;
    for(ll i=0;i<M;i++)plats.push_back({{R[i],L[i]},platNeeds[i]});
    sort(plats.begin(),plats.end());
    vector<ll>pal(N);
    fenTree palloncini = fenTree(pal);
    ll res=0;
    for(ll i=0;i<M;i++)
    {
        ll r=plats[i].first.first;
        ll l=plats[i].first.second;
        ll need=plats[i].second - palloncini.RangeSum(l,r);
        if (need < 0)need=0;
        palloncini.Update(r,need);
        res+=need;
        //cout<<need<<" "; 
        
    }
    return res;
}


#ifndef EVAL
int main() {
    int N, M;
    fin >> N >> M;
    vector<int> V(N), L(M), R(M);
    vector<long long> K(M);

    for (int &x: V) {
        fin >> x;
    }

    for (int i = 0; i < M; i++) {
        fin >> L[i] >> R[i] >> K[i];
    }

    cout << alleggerisci(N, M, V, L, R, K) << '\n';

    return 0;
}
#endif