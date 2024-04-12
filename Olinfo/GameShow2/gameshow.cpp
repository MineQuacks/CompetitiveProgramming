#include <bits/stdc++.h>
using namespace std;
vector<int>V,C,S;

int dp(int x, int mon)
{
    if(x>=V.size())return 0;
    int v1=0,v2=0;
    if(mon>=C[x])
    {
        v1 = dp(x+1,mon-C[x])+V[x];
    }
    v2=dp(x+1,mon+S[x]);
    return max(v1,v2);
}


int main()
{
    int n;cin>>n;
    V.reserve(n);
    C.reserve(n);
    S.reserve(n);
    for(int i=0;i<n;i++)cin>>V[i];
    for(int i=0;i<n;i++)cin>>C[i];
    for(int i=0;i<n;i++)cin>>S[i];
    int g=0,m=1000000;
    for(int i=0;i<100;i++)
    {
        int tmp = dp(0,i);
        if(tmp>=g)
        {
            if(tmp==g && i>m)continue;
            m=i;
            g=tmp;
        }
    }
    
}