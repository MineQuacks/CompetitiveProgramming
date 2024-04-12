#include <bits/stdc++.h>
using namespace std;
ofstream fout ("output.txt");
int main()
{
    int test;cin>>test;
    for(int t=0;t<test;t++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int edges= a*2 + b;
        int nodes=a+b+c;
        if(edges != nodes-1)cout<<-1<<endl;
        else{
            int oldLayer=c;
            int newLayer=0;
            int res=0;
            for(int j=0;j<b;j++)
            {
                oldLayer--;
                newLayer++;
                if(oldLayer==0)
                {
                    res++;
                    oldLayer=newLayer;
                    newLayer=0;
                }
            }
            for(int j=0;j<a;j++)
            {
                oldLayer-=2;
                newLayer++;
                if(oldLayer==0)
                {
                    res++;
                    oldLayer=newLayer;
                    newLayer=0;
                }
                if(oldLayer<0)
                {
                    res+=2;
                    oldLayer=newLayer-1;
                    newLayer=0;
                }
            }
            cout<<res<<endl;
        }
    }


}