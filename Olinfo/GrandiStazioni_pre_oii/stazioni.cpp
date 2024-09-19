#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
#define ll long long
#define INF 100000000000000000

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W)
{   
    vector<pair<ll,ll>>adj[N];
    for(ll i=0;i<M;i++){
        adj[B[i]].push_back({A[i],T[i]});
    }
    vector<bool>visited(N);
    vector<ll>dist(N,INF);
    priority_queue<pair<ll,ll>>pq;
    pq.push({0,N-1});
    dist[N-1]=0;
    vector<pair<ll,ll>>predec(N);
    while(!pq.empty())
    {
        ll a = pq.top().second;pq.pop();
        if(visited[a])continue;
        visited[a]=true;
        for(auto u:adj[a]){
            int b=u.first;ll w=u.second;
            if(dist[b]>dist[a]+w){
                dist[b]=dist[a]+w;
                pq.push({-dist[b],b});
                predec[b]={a,w};
            }
        }
    }
    /*for(int i=0;i<N;i++){
        cout<<i<<": "<<predec[i]<<endl;
    }*/

    /*vector<pair<ll,ll>>adj2[N];
    for(ll i=0;i<M;i++){
        adj2[A[i]].push_back({B[i],T[i]});
    }*/

    /*for(ll i=0;i<N;i++){
        ll dest=predec[i].first;
        for(ll j=0;j<adj2[i].size();j++){
            if(adj2[i][j].first==dest){
                predec[i].second=adj2[i][j].second;
                break;
            }
        }
    }*/

    ll x=0;
    ll res=0;
    while(x!=N-1)
    {
        //cout<<"x: "<<x<<" res: "<<res<<endl;
        if(V[x]!=-1){
            res+=W[x];
            ll next=V[x];
            V[x]=-1;
            x=next;         
        }else{
            res+=predec[x].second;
            x=predec[x].first;           
        }
    }
    
    return res;
}

#ifndef EVAL
int main()
{
    int N, M;
    fin >> N >> M;

    vector<int> A(M), B(M), T(M), V(N), W(N);
    for (int i = 0; i < N; i++)
        fin >> V[i];
    for (int i = 0; i < N; i++)
        fin >> W[i];
    
    for (int i = 0; i < M; i++)
        fin >> A[i] >> B[i] >> T[i];
    
    cout << viaggia(N, M, A, B, T, V, W) << '\n';
}
#endif