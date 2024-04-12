#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,x;cin>>n>>x;
    unordered_set<int>lista;
    vector<pair<ll,ll>>A;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(lista.count(a))continue;
        lista.insert(a);
        A.push_back({a,i});
    }
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            if(i==j)continue;
            if(A[i].first+A[j].first==x){
                cout<<A[i].second+1<<" "<<A[j].second+1;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}