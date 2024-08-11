#include <bits/stdc++.h>
#define MAXN 100001
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
vector<ll> winNodes;
vector<ll>adj[MAXN];

int main(){
    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        ll N,A,B;
        fin>>N>>A>>B;
        for(int i=0;i<N;i++)adj[i].clear();
        winNodes.clear();
        for(int i=0;i<A;i++)
        {
            ll node;fin>>node;
            winNodes.push_back(node);
        }
        for(int i=0;i<B;i++)
        {
            ll node1,node2;
            fin>>node1>>node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        //bfs
        queue<ll>q;
        vector<bool>visited(N);
        vector<pair<ll,ll>>distance(N);
        for(auto i:winNodes){
            distance[i]={0,i};
            visited[i]=true;
            q.push(i);
        }
        while(!q.empty())
        {
            ll a=q.front();
            q.pop();
            for(auto u:adj[a])
            {
                if(visited[u])continue;
                visited[u]=true;
                q.push(u);
                distance[u]={distance[a].first+1,u};
            }
        }

        sort(distance.begin(),distance.end());
        fout<<"Case #"<<t<<": "<<distance[N-1].second<<" "<<distance[N-1].first+1<<endl;
    }
}









