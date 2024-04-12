#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int persone=0;
    priority_queue<int,vector<int>,greater<int>>entranti;
    priority_queue<int,vector<int>,greater<int>>uscenti;
    for(int i=0;i<n;i++)
    {
        
        int a,b;
        cin>>a>>b;
        entranti.push(a);
        uscenti.push(b);
    }
    int res=0;
    
    while (!uscenti.empty())
    {
        
        int a=1000001,b=1000001;
        if(!entranti.empty())a=entranti.top();
        b=uscenti.top();
        if(a<b)
        {
            entranti.pop();
            persone++;
            res+=persone;
        }else
        {
            uscenti.pop();
            persone--;
        }
    }
    cout<<res;
    

    
}