#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout("output.txt");

vector<int> execute(int N, int K, int D, vector<int> A)
{
    vector<int>B;
    B.resize(N,1);
    int id=0;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            int pos =(j - id%N);
            if(pos<0)pos+=N;
            B[j]=(B[j]*A[pos])%1000000007;
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

}
#endif