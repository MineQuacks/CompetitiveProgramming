#include<bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long
#define MOD 1000000007

struct fenwickTree{

    ll LSB(ll x){return x & (-x);}
    vector<ll>fenTree;

    void update(ll x,ll val){
        while(x<fenTree.size()){
            fenTree[x]+=val;
            x+=LSB(x);
            x%=MOD;
        }
    }

    ll sum(ll x)
    {
        ll res=0;
        while(x>0){
            res+=fenTree[x];
            res%=MOD;
            x-=LSB(x);
        }
        return res;
    }
    ll range_sum(ll l, ll r){
        return sum(r)-sum(l-1);
    }

    fenwickTree(vector<ll>startingValues)
    {
        fenTree.resize(startingValues.size()+1);
        for(ll i=0;i<startingValues.size();i++){
            update(i+1,startingValues[i]);
        }
    }

};

int main()
{
    ll N;fin>>N;
    vector<ll>A(N);
    for(ll i=0;i<N;i++)fin>>A[i];
    vector<ll>S(N);
    fenwickTree fenTree = fenwickTree(S);
    vector<pair<ll,ll>>B(N);
    for(ll i=0;i<N;i++){
        B[i]={A[i],i};
    }
    sort(B.begin(),B.end());
    ll x=0;
    for(ll i=0;i<N;i++){
        if(i!=0 && B[i].first == B[i-1].first)x--;
        A[B[i].second]=x+1;    
        x++;
    }
    /*cout<<"A: ";
    for(int i:A)cout<<i;
    cout<<endl;*/

    for(ll i=0;i<N;i++){
        fenTree.update(A[i],1+fenTree.sum(A[i]-1));
    }
    //for(int u: fenTree.fenTree)cout<<u<<" ";
    fout<<fenTree.sum(N);
}