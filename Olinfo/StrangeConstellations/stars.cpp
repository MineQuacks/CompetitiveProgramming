#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    unordered_map<int,int>horizontals;
    unordered_map<int,int>verticals;
    int n;fin>>n;
    vector<pair<int,int>>stars;
    for(int i=0;i<n;i++)
    {
        int a,b;
        fin>>a>>b;
        stars.push_back({a,b});
        horizontals[a]++;
        verticals[b]++;
    }
    long long res=0;
    for(auto star:stars){
        int x = star.first;
        int y = star.second;
        res+= (horizontals[x]-1)*(verticals[y]-1);
    }
    fout<<res;

}