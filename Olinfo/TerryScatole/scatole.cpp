#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");
ll A,B;
ll g;
vector<string>memo;


string dp(ll giorno, ll a, ll b)
{    
    if(a==A && b==B)return "";
    if(giorno>g)return "IMPOSSIBLE";
    if(a>A)return "IMPOSSIBLE";
    if(b>B)return "IMPOSSIBLE";
    if(memo[giorno]!= "-1")return memo[giorno];
    string res1 ="E";
    if(a+giorno<=A)res1 = '1' + dp(giorno+1,a+giorno,b);
    if(res1[res1.length()-1]!='E'){
        memo[giorno]=res1;
        return res1;
    }
    string res2 = "E";
    if(b+giorno<=B)res2 = '2' + dp(giorno+1,a,b+giorno);
    if(res2[res2.length()-1]!='E'){
        memo[giorno]=res2;
        return res2;
    }
    return "IMPOSSIBILE";
}

int main()
{
    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {
        fin>>A>>B;
        int sum = A+B;
        int x =0;
        g=1;
        while(x<sum){x+=g;g++;}
        memo.resize(g+1, "-1");
        for(int i=0;i<g+1;i++)memo[i]="-1";
        fout<<"Case #"<<t<<": "<<dp(1,0,0)<<endl;
    }
    
}