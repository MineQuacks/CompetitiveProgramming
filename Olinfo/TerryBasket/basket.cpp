#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    ll test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        ll n;fin>>n;
        unordered_map<int,int> A;
        unordered_map<int,int> B;
        unordered_set<ll>scelte;
        for(int i=0;i<n;i++){
            ll a;fin>>a;
            scelte.insert(a);
            A[a]++;
        }
        ll res=0;
        for(int i=0;i<n;i++){
            ll a;fin>>a;
            B[a]++;
        }
        for(auto i=scelte.begin();i!=scelte.end();i++)
        {       
            res+=min(A[*i],B[*i]);
        }
        fout<<"Case #"<<t<<": "<<res<<endl;
    }
}