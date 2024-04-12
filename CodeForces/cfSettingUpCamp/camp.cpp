#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int test;fin>>test;
    for(int t=0;t<test;t++)
    {
        ll a,b,c;fin>>a>>b>>c;
        ll res=0;
        ll bc=b+c;
        if(b%3==0 || c>=3-b%3)
        {
            res+=a;
            res+=b/3;
            b-=3*(b/3);
            if(b!=0){
                res++;
                c=c-(3-b);
            }
            res+=c/3;
            c-=3*(c/3);
            res+=c/2;
            c-=2*(c/2);
            res+=c;

        }else res=-1;
        fout<<res<<"\n";
    }



}