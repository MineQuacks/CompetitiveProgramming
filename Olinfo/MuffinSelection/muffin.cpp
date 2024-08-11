#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int n,k;
    fin>>n>>k;
    vector<int>M(n);
    for(int i=0;i<n;i++)fin>>M[i];
    int sum=0;
    for(int i=0;i<k;i++)sum+=M[i];
    int maxSum=sum;
    for(int i=k;i<n;i++)
    {
        sum+=M[i];
        sum-=M[i-k];
        cout<<sum<<endl;
        maxSum=max(maxSum,sum);
    }
    fout<<maxSum;
}