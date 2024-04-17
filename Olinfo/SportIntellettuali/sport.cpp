#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
    int n;fin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)fin>>A[i];
    vector<int>res;
    for(int i=0;i<n;i++){
        //sinistra
        int x =0;
        for(int j=0;j<i;j++){
            if(A[j]%2==0)x++;
            else x--;
        }
        if(x!=0)continue;
        x=0;
        for(int j=i+1;j<n;j++){
            if(A[j]%2==0)x++;
            else x--;
        }
        if(x!=0)continue;
        res.push_back(A[i]);
    }
    fout<<res.size()<<endl;
    for(int a:res)fout<<a<<" ";
}