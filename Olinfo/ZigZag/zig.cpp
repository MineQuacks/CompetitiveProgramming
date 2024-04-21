#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int n;fin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)fin>>A[i];
    if(n==1){
        fout<<1;
        return 0;
    }
    int res=1;
    vector<bool>pos;
    for(int i=1;i<n;i++){
        if(A[i-1] - A[i] >= 0)pos.push_back(true);
        else pos.push_back(false);
    }
    bool prim=true;
    for(int i=1;i<n;i++){
        if(prim != pos[i]){
            res++;
            prim = !prim;
        }
    }
    int res2=1;
    prim = false;
    for(int i=1;i<n;i++){
        if(pos[i] != prim){
            res2++;
            prim = !prim;
        }
    }

    fout<<max(res,res2);
}