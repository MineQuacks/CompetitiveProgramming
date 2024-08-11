#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector<int> segtree;
int n;
int originalN;

void printSeg()
{
    for(auto u:segtree)cout<<u<<" ";
    cout<<endl;
}

void inizializza(int N, vector<int> H)
{
    originalN=N;
    H.resize(1<<(int)ceil(log2(H.size())));
    N=H.size();
    segtree.resize(N*2);
    for(int i=segtree.size()-1;i>=segtree.size()-N;i--){
        segtree[i]=H[i-N];
    }
    for(int i=N-1;i>0;i--)
    {
        segtree[i]=max(segtree[i*2],segtree[i*2+1]);
    }
    n=N;
    //printSeg();
}

void cambia(int x, int h)
{
    segtree[x+n]=h;
    x=x+n;
    x/=2;
    while(x!=0){     
        segtree[x]=max(segtree[x*2],segtree[x*2+1]);   
        x/=2;
    }        
    //printSeg();
}

int destra(int u, int l, int r, int tl, int val)
{
    //cout<<"u:" << u<<endl;
    //cout<<"l: "<<l<<" r: "<<r<<endl;
    if(r<tl || l>=n)return -1;
    if(segtree[u]<=val)return -1;
    if(l==r)return l;
    int m = (l+r)/2;
    int lc = destra(u*2,l,m,tl,val);
    if(lc != -1)return lc;
    int rc= destra(u*2+1,m+1,r,tl,val);
    return rc;
}

int sinistra(int u, int l, int r, int tr, int val)
{
    //cout<<"u:" << u<<endl;
    //cout<<"l: "<<l<<" r: "<<r<<endl;
    if(l>tr || r<0)return -1;
    if(segtree[u]<=val)return -1;
    if(l==r)return l;
    int m = (l+r)/2;
    int rc= sinistra(u*2+1,m+1,r,tr,val);
    if(rc != -1)return rc;
    int lc = sinistra(u*2,l,m,tr,val);
    return lc;
}

pair<int, int> chiedi(int x)
{
    int r = destra(1,0,n-1,x,segtree[n+x]);
    int l = sinistra(1,0,n-1,x,segtree[n+x]);
    if(r==-1)r=originalN-1;
    if(l==-1)l=0;
    pair<int,int>sol= {l,r};
    return sol;
}

#ifndef EVAL
int main()
{
    int N,M;fin>>N>>M;
    vector<int>A(N);
    for(int i=0;i<N;i++)fin>>A[i];
    inizializza(N,A);
    for(int i=0;i<M;i++){
        char q;fin>>q;
        if(q=='Q'){
            int a;fin>>a;
            pair<int,int>sol= chiedi(a);
            fout<<sol.first<<" "<<sol.second<<endl;
        }else{
            int a,b;fin>>a>>b;
            cambia(a,b);
        }
    }
}
#endif