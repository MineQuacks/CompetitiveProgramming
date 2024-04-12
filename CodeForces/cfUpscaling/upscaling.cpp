#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    int test;fin>>test;
    for(int t=0;t<test;t++)
    {
        int n;fin>>n;
        char col='#';
        char s='#';
        
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                fout<<s;

                if(j%2==0)
                {
                    if(s=='#')s='.';
                    else s='#';
                }
            }
            fout<<"\n";
            if(i%2==0)
            {
                if(col=='#')col='.';
                else col='#';
            }
            s=col;
        }

    }
}