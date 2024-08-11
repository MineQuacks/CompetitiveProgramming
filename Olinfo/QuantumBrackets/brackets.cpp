#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main()
{
    ll tests;
    fin>>tests;
    for(int t=0;t<tests;t++)
    {
        ll n,m;
        fin>>n>>m;
        stack<ll>brackets;
        for(int i=0;i<n;i++)
        {
            ll newBracket;
            fin>>newBracket;
            if(brackets.empty()){
                brackets.push(newBracket);
            }
            else if(brackets.top() != newBracket){
                brackets.push(newBracket);
            }else if(brackets.top() == newBracket){
                brackets.pop();
            }
        }
        fout<<brackets.empty()<<'\n';
    }
}