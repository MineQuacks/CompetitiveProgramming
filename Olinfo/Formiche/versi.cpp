#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
    int n;fin>>n;
    queue<int>A;
    queue<int>B;
    for(int i=0;i<n;i++){
        int a;fin>>a;
        A.push(a);
    }
    for(int i=0;i<n;i++){
        int a;fin>>a;
        B.push(a);
    }
    int res=0;
    while(!A.empty() && !B.empty()){
        if(A.front() < B.front()){
            A.pop();
            B.pop();
            res++;
        }else B.pop();
    }
    fout<<res;
}