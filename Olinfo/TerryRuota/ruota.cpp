#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long
int main()
{
    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        int n;fin>>n;
        vector<int>A(n);
        for(int i =0;i<n;i++)fin>>A[i];
        bool ok=true;
        ll res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n+i;j++)
            {
                int x =j;
                if(j>=n)x-=n;
                if(A[j-i]!=A[x]){ok = false;break;}
            }
            if (ok)res++;
            ok=true;
        }
        fout<<"Case #"<<t<<": "<<res<<endl;
    }


}