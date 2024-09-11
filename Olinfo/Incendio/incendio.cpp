#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");



int alzati(int N, int M, int X[], int Y[])
{
    vector<bool>visited(M+2);
    vector<int>distanze(M+2,1000000000);
    set<int> pq;
    pq.insert(M);
    distanze[M]=0;
    while(!pq.empty())
    {
        int minFound=1000000000;
        int a;
        for(int u:pq){
            if(distanze[u]<minFound){
                a=u;
                minFound=distanze[u];
            }
        }
        pq.erase(a);
        if(visited[a])continue;
        visited[a]=true;
        for(int i=0;i<M+2;i++){
            if(i==a)continue;
            int w=0;
            if(i<M && a<M){
                if(X[i]==X[a]){
                    w=abs(Y[i]-Y[a])/2;
                }else if(Y[i]==Y[a]){
                    w=abs(X[i]-X[a])/2;
                }else{
                    w=(abs(X[i]-X[a])+abs(Y[i]-Y[a])-1)/2;
                }
            }else if((i==M && a==M+1) || (i==M+1 && a==M)){
                w=N;
            }
            else if (i==M || a==M){
                //down left walls
                int x,y;
                if(i==M){
                    x=X[a];y=Y[a];
                }else{
                    x=X[i];y=Y[i];
                }
                w=min(x,N-y-1);
            }else if(i==M+1 || a==M+1){
                //top right walls
                int x,y;
                if(i==M+1){
                    x=X[a];y=Y[a];
                }else{
                    x=X[i];y=Y[i];
                }
                w=min(N-x-1,y);
            }
            if(w<0)w=0;
            if(max(distanze[a],w)<distanze[i]){
                distanze[i]=max(distanze[a],w);
                pq.insert(i);
            }
        }
    }
    return distanze[M+1]-1;
}



#ifndef EVAL
int main()
{
    int N,M;fin>>N>>M;
    int X[M],Y[M];
    for(int i=0;i<M;i++)fin>>X[i]>>Y[i];
    cout<<"res= "<<alzati(N,M,X,Y)<<endl;
}
#endif