#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int n,m;fin>>n>>m;
    vector<string>rows(n,"");
    vector<string>col(m,"");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;fin>>a;
            rows[i]+=a;
            col[j]+=a;
        }
    }
    
    int res = n*m;
    for(int i=0;i<n;i++){
        if(rows[i]==("a"*m)){
            n--;

        }
    }
}