#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int n,t,p;
    fin>>n>>t>>p;
    vector<int>prob(t);
    vector<vector<int>>res(t);
    int tot;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<t;j++)
        {
            int a;fin>>a;
            if(a==1){
                prob[j]++;
                res[j].push_back(i);
            }
            
        }
    }
    tot=0;
    vector<int>scores(t);
    for(int i=0;i<t;i++)scores[i]=n-res[i].size();
    for(int i=0;i<t;i++)
    {
        for(auto j:res[i])
        {
            
        }
    }
    cout<<tot;

}
