#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int n,m;
vector<vector<char>>grid(20,vector<char>(20));
vector<vector<bool>>visited(20,vector<bool>(20));



void solve(int row,int col, vector<int>currentPipes,int )
{

    //destra
    if(col<m-2 && !visited[row][col+2])
    {
        visited[row][col+2]=true;
        currentPipes[5]--;
        solve(row,col,currentPipes); 
        visited[row][col+2]=false;
        currentPipes[5]++; 
    }
    //sinistra
    if(col>1 && !visited[row][col-1])
    {
        visited[row][col+2]=true;
        currentPipes[5]--;
        solve(row,col,currentPipes); 
        visited[row][col+2]=false;
        currentPipes[5]++; 
    }
    
}



int main()
{
    int tests;fin>>tests;
    for(int t=1;t<=tests;t++)
    {
        fin>>n>>m;
        vector<int>tubi(6);
        for(int i=0;i<6;i++)
        {
            char tmp;int a;
            cin>>tmp>>a;
            tubi[a]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                fin>>grid[i][j];
            }
        }

    }
   
}