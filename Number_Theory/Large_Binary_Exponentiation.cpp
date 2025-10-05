#include<bits/stdc++.h>
using namespace std;
const int Mod=1e18+7;
//a<=1e18, Mod<=1e18
int binExp(long long a, long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1) ans=binMultiply(ans,a);
        a=binMultiply(a,a);
        b>>=1;
    }
    return ans;
}
int binMultiply(long long a, long long b)
{
    long long ans=0;
    while(b)
    {
        if(b&1) ans=(ans+a)%Mod;
        a=(a+a)%Mod;
        b>>=1;
    }
    return ans;
}
int main()
{

}