#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout("output.txt");

vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P){
    //prefix sums array
    vector<long long> prefixSums(T);
    vector<ll> prefixSumsQuantity(T);
    prefixSums[0]=0;
    prefixSumsQuantity[0]=S[0];
    for(ll i=1;i<T;i++){
        prefixSums[i]=prefixSums[i-1]+S[i]*i;
        prefixSumsQuantity[i]=S[i]+prefixSumsQuantity[i-1];
    }
    vector<ll>res(M);
    //for(int i:prefixSums)cout<<i<<" ";
    //per ogni valigia
    for(ll i=0;i<M;i++)
    {
        //bs
        ll l=0,r=T-1,m;
        ll maxPos;
        while(l<=r){
            
            m=(l+r)/2;
            if(prefixSums[m]>P[i]){
                r=m-1;
            }else{
                maxPos=m;
                l=m+1;
            }
        }
        
        res[i]=prefixSumsQuantity[maxPos];
        if(maxPos!=T-1){
            ll space=P[i]-prefixSums[maxPos];
            res[i]+=space/(maxPos+1);
        }
        //cout<<"valigia: "<<i<<" maxPos: "<<maxPos<<" res: "<<res[i]<<endl;
    }
    return res;
}

#ifndef EVAL
int main()
{
    cout<<"x";
    int T,M;
    fin>>T>>M;
    vector<ll>S(T),P(M);
    for(int i=0;i<T;i++)fin>>S[i];
    for(int i=0;i<M;i++)fin>>P[i];
    vector<ll> res=calcola(T,M,S,P);
    for(auto s:res)fout<<s<<" ";
}
#endif