#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    long long n;fin>>n;
    long long k;fin>>k;
    string parola;fin>>parola;
    vector< long long> word(n);
    for(int i=0;i<n;i++)
    {
        word[i] = parola[i];
    }
    deque<char> res;
    res.push_back(parola[0]);
    long long tolti=0;
    for( long long i=1;i<n;i++)
    {
        if(word[i]>word[i-1]) 
        {
            while(!res.empty() && tolti < k)
            {
                //cout<<res.back()<<endl;
                if(res.back()>= word[i])break;
                tolti++;
                res.pop_back();             
            }      
        }
        res.push_back(parola[i]);
    }
    string stampa = "";
    while(!res.empty())
    {
        stampa += res.front();
        res.pop_front();
    }
    for(int i=0;i<stampa.length()-(k-tolti);i++)cout<<stampa[i];


   // if(tolti < k)assert(0);
    //cout<<endl;

    return 0;
}