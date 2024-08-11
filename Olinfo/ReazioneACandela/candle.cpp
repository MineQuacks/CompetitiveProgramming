#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

void brucia(int N, vector<int> &M, vector<int> &B, vector<long long> &T)
{
    vector<int>closestRight(N);
    vector<int>closestLeft(N);
    stack<int>stak;

}

#ifndef EVAL
int main(){
    int n;fin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;i++)fin>>A[i]>>B[i];
    vector<long long>T(n);
    brucia(n,A,B,T);
    for(auto r : T)fout<<r<<" ";
}
#endif