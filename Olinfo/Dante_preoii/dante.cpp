#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int rimembra(int N, int K, vector<int> V){
    vector<ll>A(N+1);
    for(ll i=1;i<=N;i++)A[i]=V[i-1];

    queue<ll>skips;
    ll k=K;
    ll maxLenght=0;
    ll currLenght=0;
    if(K!=0){
    for(ll i=1;i<=N;i++)
    {
        if(A[i]==1)currLenght++;
        else{
            if(k<=0){
                k++;
                ll lastSkip=i+1;
                if(!skips.empty())
                {
                    lastSkip= skips.front();
                    skips.pop();                    
                }else k--;
                maxLenght=max(maxLenght,currLenght);
                currLenght=i-lastSkip-1;
                
            }        
            if(k>0){
                currLenght++;
                skips.push(i);
            }
            k--;
        }
    }
    maxLenght=max(maxLenght,currLenght);
    return maxLenght;
    }else{
        int maxLenght =0;
        int curr=0;
        for(int i:A){
            if(i==1)curr++;
            else{
                maxLenght=max(maxLenght,curr);
                curr=0;
            }
        }
        maxLenght=max(maxLenght,curr);
        return maxLenght;
    }
}


#ifndef EVAL
int main()
{
    int N,K;
    fin>>N>>K;
    vector<int>V(N);
    for(int i=0;i<N;i++)fin>>V[i];
    cout<<rimembra(N,K,V);
}
#endif