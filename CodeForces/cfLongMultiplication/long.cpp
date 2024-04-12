#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int test;cin>>test;
    for(int t=0;t<test;t++)
    {
        ll a,b;
        cin>>a>>b;
        string sa=to_string(a);
        string sb=to_string(b);
        string osa =sa;
        string osb = sb;
        for(ll i=sa.size()-1;i>=0;i--)
        {
            string swa = sa;
            string swb = sb;
            swa[i]=osb[i];
            swb[i]=osa[i];
            if(stoi(swa)*stoi(swb) > stoi(sa)*stoi(sb)){
                sa=swa;
                sb=swb;
            }
        }
        cout<<sa<<endl<<sb<<endl;



    }

}