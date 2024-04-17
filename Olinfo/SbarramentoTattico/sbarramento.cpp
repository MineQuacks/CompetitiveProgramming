#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int n,r;
    fin>>n>>r;
    r--;
    priority_queue<pair<int,pair<int,int>>>soldati;
    for(int i=0;i<n;i++){
        int a,b;
        fin>>a>>b;
        a--;b--;
        soldati.push({abs(r-a),{a,b}});
    }
    vector<bool>occupied(n);
    int res=0;
    while(!soldati.empty()){
        int x = soldati.top().second.first;
        int y = soldati.top().second.second;
        soldati.pop();
        int i=0;
        while (true){
            if(y+i <= n-1 && !occupied[y+i]){
                occupied[y+i]=true;
                res+=abs(x-r) + abs(y+i-y);
                break;
            }
            if(y-i >= 0 && !occupied[y-i]){
                occupied[y-i]=true;
                res+=abs(x-r) + abs(y-i-y);
                break;
            }
            i++;
        }  
    }
    fout<<res;
}