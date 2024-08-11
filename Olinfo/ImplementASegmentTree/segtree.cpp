#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct Segtree
{
    vector<int> seg;
    int n;
    Segtree(vector<int>numbers)
    {
        numbers.resize(1<<(int)ceil(log2(numbers.size())));
        n=numbers.size();   
        seg.resize(2*n);
        cout<<seg.size()<<endl;
        int j=n-1;
        for(int i=seg.size()-1;j>=0;i--)
        {
            seg[i]=numbers[j];
            j--;
        }
        for(int i=seg.size()-1;seg[1]==0;i-=2)
        {
            seg[i/2]=seg[i]+seg[i-1];
        }
        for(int o:seg)
        {
            cout<<o<<" ";
        }   
    }

    int GetSum(int l, int r)
    {
        l+=n; r+=n;
        r--;
        int s=0;
        while (l<=r)
        {
            if(l%2==1) s+=seg[l++];
            if(r%2==0) s+=seg[r--];
            l/=2;r/=2;
        }
        return s;        
    }
    void Update(int u, int x)
    {
        seg[u+n]=x;
        int node = (u+n)/2;
        while(node!=1){
            seg[node]=seg[node*2]+seg[node*2+1];
            node/=2;
        }
    }
};




int main()
{
    vector<int>numb={5,8,6,3,2,7,2,4,4};
    Segtree sg = Segtree(numb);
    cout<<endl<<sg.GetSum(0,2);
    sg.Update(0,4);
    cout<<endl<<sg.GetSum(0,2);
}