#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
long long riciclo(int N, int M, vector<int> T, vector<int> P)
{
    queue<ll>PP;
    for(ll i=0;i<M;i++){
        PP.push(P[i]);
    }
    sort(T.begin(),T.end());
    ll res=0;
    ll curr=0;
    ll w=-1;
    ll spazio=0;

    for(ll i=0;i<N;i++){
        spazio=T[i];
        if(PP.empty() && spazio<(int)pow(2,w))break;
        if(curr==0){
            curr=PP.front();
            PP.pop();
            w++;
        }
        while(spazio>=(ll)pow(2,w)){
            if(spazio/(ll)pow(2,w)>=curr){
                res+=curr;
                spazio-=curr*(ll)pow(2,w);
                curr=0;
            }else{
                res+=spazio/(ll)pow(2,w); // 4
                curr-=spazio/(ll)pow(2,w);
                spazio-=spazio/(ll)pow(2,w)*(ll)pow(2,w);        
            }
            
            if(PP.empty())break;
            if(curr==0){
                curr=PP.front();
                PP.pop();
                w++;
            }     
        }
    }
    return res;

}

#ifndef EVAL
int main()
{
    int n,m;
    fin>>n>>m;
    vector<int>F(n),T(m);
    for(int i=0;i<n;i++)fin>>F[i];
    for(int i=0;i<m;i++)fin>>T[i];
    fout<<riciclo(n,m,F,T);
}
#endif