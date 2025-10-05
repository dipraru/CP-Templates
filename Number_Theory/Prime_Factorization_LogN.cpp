#include<bits/stdc++.h>
using namespace std;

const int N=1e7+5;
int hp[N], lp[N];
void seive()
{
    for(int i=0;i<N;i++) hp[i]=lp[i]=i;
    for(int i=2;i<N;i++)
    {
        if(hp[i]==i)
        {
            for(int j=2*i;j<N;j+=i) hp[j]=i, lp[j]=min(i,lp[j]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int nn=n;
    //process 1
    vector<int> p1,p2;
    while(n>1)
    {
        if(p1.empty()||p1.back()!=hp[n]) p1.push_back(hp[n]);
        n/=hp[n];
    }
}