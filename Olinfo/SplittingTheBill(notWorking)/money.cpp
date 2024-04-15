#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
    int n,m;
    fin>>n>>m;
    vector<int>money(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        fin>>a>>b>>c;
        money[a]-=c;
        money[b]+=c;
    }
    queue<int>debts;
    queue<int>profits;
    for(int p:money){
        if(p<0)debts.push(-p);
        if(p>0)profits.push(p);
    }
    int d=0,p=0;
    int res=0;
    for(int i=0;i<n;i++){
        cout<<money[i]<<endl;
    }
    while(!debts.empty() && !profits.empty()){
        if(d==0){
            d=debts.front();
            debts.pop();
        }
        if(p==0){
            p=profits.front();
            profits.pop();
        }
        if(d <= p){
            d=0;
            p-=d;
        }else{
            p=0;
            d-=p;
        }
        res++;
    }   
    fout<<res;

}