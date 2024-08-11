#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout("output.txt");
#define ll long long

vector<int> execute(int N, int K, int D, vector<int> A)
{
    vector<int>B;
    B.resize(N,1);
    int loopLenght;
    if(D!=0 && N%(D%N)==0)loopLenght = N/(D%N);
    else if(D==0)loopLenght=1;
    else loopLenght = N;
    
    //cout<<"loop lenght: "<<loopLenght<<endl;
    vector<ll> quantityMult;
    quantityMult.resize(N,1);
    for(int i=0;i<N;i++)
    {
        if(quantityMult[i]!=1)continue;
        int j=i;
        do
        {
            quantityMult[i]*=A[j]%1000000007;
            quantityMult[i]%=1000000007;
            j+=D;
            j%=N;
        } while(j!=i);
        j=i;
        do
        {
            quantityMult[j]=quantityMult[i];
        } while(j!=i);
    }
    int numberOfLoops = K/loopLenght;
    if(numberOfLoops!=0){
        for(int i=0;i<N;i++){
            for(int pows=0;pows<numberOfLoops;pows++){
                B[i]=(ll)B[i]*quantityMult[i]%10000000007;
            }
        }
    }
    int extraCicles=K%loopLenght;
    //cout<<"extra: "<<extraCicles<<endl;
    int id=0;
    for(int i=0;i<extraCicles;i++){
        for(int j=0;j<N;j++){
            int pos =(j - id%N);
            if(pos<0)pos+=N;
            B[j]=((ll)B[j]*(ll)A[pos])%1000000007;
        }      
        id+=D;
    }
    return B;
}

#ifndef EVAL
int main(){
    int n,k,d;
    fin>>n>>k>>d;
    vector<int>A(n);
    for(int i=0;i<n;i++)fin>>A[i];
    vector<int>B = execute(n,k,d,A);
    for(int b:B)cout<<b<<" ";
    cout<<endl;
}
#endif