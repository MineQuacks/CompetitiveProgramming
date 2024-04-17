#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

long long stima(int N, int h[]){
    long long lr=1000000001,ll=0;
    long long res;
    long long m;
    long long currm;
    long long currDist;
    while(ll<=lr){
        m=(lr+ll)/2;
        long long primo=m;
        long long dist1=0;
        for(long long j=0;j<N;j++){
                dist1+=abs(primo+j - h[j]);
        }
        long long dist2=0;
        for(long long j=0;j<N;j++){
                dist2+=abs(primo+1+j - h[j]);
        }
        //cout<<dist1<<" "<<dist2<<endl;
        currDist = dist1;
        if(dist1 < dist2){
            lr = m-1;
            currm = dist1;
        }else {
            ll = m+1;
            currm=dist2;
        }
    }
    return currm;
}

int main(){
    int n;fin>>n;
    int A[n];
    for(int i=0;i<n;i++)fin>>A[i];
    fout<<stima(n,A);
}