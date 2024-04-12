#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int n,m;fin>>n>>m;
    vector<int>R(n+1);
    for(int i=1;i<n+1;i++)fin>>R[i];
    vector<int>W(m+1);
    for(int i=1;i<m+1;i++)fin>>W[i];
    queue<int>cars;
    vector<int>Parc(n+1);
    int a;
    int tot=0;
    for(int i=0;i<2*m;i++)
    {
        fin>>a;
        
        if(a>0)
        {
            
            int libero=-1;
            for(int z=1 ;z<n+1;z++)
            {
                if(a==4 & z==2)cout<<Parc[z]<<endl;
                if(Parc[z]<=0)
                {
                    libero = z;
                    cout<<a<<" "<<z<<endl;
                    break;
                }
            }
            if(libero==-1){cars.push(a);cout<<"pene "<<a<<endl;}
            else{
                
                Parc[libero] = a;
                tot+=W[a]*R[libero];
            }
        }else
        {
            a=a*-1;
            for(int z=0 ;z<Parc.size();z++)
            {
                if(Parc[z]==a)
                {
                    Parc[z]=0;
                    if(!cars.empty())
                    {
                        Parc[z]=cars.front();
                        tot+=W[cars.front()]*R[z];
                        cars.pop();
                    }else cout<<"cazzo "<< a <<" "<<cars.front()<<endl;
                    break;
                }
            }

        }



    }
    cout<<tot;



    
}