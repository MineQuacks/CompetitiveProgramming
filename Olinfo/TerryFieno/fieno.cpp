#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");


int main()
{
    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        long long n;fin>>n;
        vector<int>H(n);
        for(int i=0;i<n;i++)fin>>H[i];
        long long promMax=0;
        long long res=-1;
        for(int i=1;i<n-1;i++)
        {
            if(H[i]>H[i-1] && H[i]>H[i+1])
            {
                long long p=min(H[i]-H[i-1],H[i]-H[i+1]);
                if(p>promMax)
                {
                    promMax=p;
                    res=i;
                }
            }
        }
        fout<<"Case #"<<t<<": "<<res<<endl;
    }
    

}