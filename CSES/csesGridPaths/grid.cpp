#include <bits/stdc++.h>
#define ll long long
#define MAX 1000
using namespace std;
ll memo[MAX][MAX];
bool grid[MAX][MAX];
ll solve(ll row,ll col)
{
    if(!grid[row][col])return 0;
    if(row == 0 && col == 0)return 1;
    if(row<0 || col<0 )return 0;
    if (memo[row][col]==-1)
    {
        memo[row][col]+=solve(row-1,col) + solve(row,col-1)+1; 
        memo[row][col]%=1000000007;
    }
    return memo[row][col];
}


int main()
{
    ll n;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)memo[i][j]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=0;j<n;j++)
        {
            if(a[j]=='.')grid[i][j]=true;
            else grid[i][j]=false;
        }
    }

    cout<<solve(n-1,n-1);

}