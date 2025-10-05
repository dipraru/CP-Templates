#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
int binExpRecur(int a,int b) //a^b
{
    if(b==0) return 1;
    int res=binExpRecur(a,b/2);
    if(b&1) return a*((res*1ll*res)%Mod)%Mod;
    else return (res*1ll*res)%Mod;
}
int binExpIter(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=(ans*1ll*a)%Mod;
        a=(a*1ll*a)%Mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    
}