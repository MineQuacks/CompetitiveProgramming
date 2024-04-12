#include <bits/stdc++.h>
using namespace std;
#define ll long long
ifstream fin ("input.txt");
ofstream fout ("output.txt");
ll A,B;
ll g;
vector<int>num;


bool dp(ll giorno, ll a,vector<int>V)
{     
    if(a == A){
        num=V;
        return true;
    }
    if(dp(giorno+1,a,V))return true;
    V.push_back(giorno);
    if(dp(giorno+1,a+giorno,V))return true;  
    return false; 
}

int main()
{
    cout<<"aaaa";

    int test;fin>>test;
    for(int t=1;t<=test;t++)
    {cout<<"b";
        fin>>A>>B;
        int sum = A+B;
        int x =0;
        g=1;
        while(x<sum){x+=g;g++;}
        g--;

        string output="";
        vector<int> tmp(0);
        cout<<"b";
        dp(1,0,tmp);
        cout<<"A";
        int sum1=0;
        unordered_set<int>numeri1;
        for(auto c:num)
        {
            sum1+=c;
            numeri1.insert(c);
        }
        
        if(x - sum1 != B)output = "IMPOSSIBILE";
        else{
            for(int i=1;i<=g;i++)
            {
                if(numeri1.count(i))output+='1';
                else output+='2';
            }
        }
    
        fout<<"Case #"<<t<<": "<<output<<endl;
    }
    
}