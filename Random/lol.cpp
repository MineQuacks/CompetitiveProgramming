#include <bits/stdc++.h>
using namespace std;
ofstream fout ("messaggioSegretoPerChri.txt");
int main()
{
    string messaggio_segretissimo= "bgqhrsh`m^f`x";
    for(int i=0;i<messaggio_segretissimo.size();i++)
    {
        messaggio_segretissimo[i]++;
        fout<<messaggio_segretissimo[i];
    }
}