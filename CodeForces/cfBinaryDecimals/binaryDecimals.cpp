#include <bits/stdc++.h>
using namespace std;
vector<int>nums;
unordered_set<int>numsSet;
void solve(string s)
{
    if(s.size()==6)
    {
        if(stoi(s)!=0 && stoi(s)!=1){
            nums.push_back(stoi(s));
            numsSet.insert(stoi(s));
        }
        return;
    }
    solve(s+"0");
    solve(s+="1");
}

int main()
{
    solve("");
    
    int test;cin>>test;
    for(int t=0;t<test;t++)
    {
        bool res=false;
        int n;cin>>n;
        for(int i=0;i<nums.size();i++)
        {
            if(numsSet.count(n)){
                res=true;
                break;
            }
            if(n==1){
                res=true;
                break;
            }
            if(n%nums[i]==0){
                n/=nums[i];
                i--;
            }
        }
        if(res)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}