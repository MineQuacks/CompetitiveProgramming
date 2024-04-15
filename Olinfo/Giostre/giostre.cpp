#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
    int a,b;fin>>a>>b;
    set<int>visits;
    int c=0;
    int res=0;
    while(true){
        c+=b;
        c%=a;
        if(visits.count(c))break;
        visits.insert(c);
        res++;
    }
    int res2=0;
    int c2=0;
    b=20;
    int visiteds=0;
    while(true){
        visits.clear();
        visiteds=0;
        while(true){
        c2+=b;
        c2%=a;
        if(visits.count(c2))break;
        visits.insert(c2);
        visiteds++;
      }
      if(visiteds==a)break;
      b++;
    }
  
    fout<<res<<" "<<b;
}