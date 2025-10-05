//Eular's Theorem-> (a^b)%M=(a^(b%Φ(M)))%M
#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int binExp(int a, long long b, int m)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=(ans*1ll*a)%m;
        a=(a*1ll*a)%m;
        b>>=1;
    }
    return ans;
}
int main()
{
    int a,b,c;
    //a^b^c
    cout << binExp(50,binExp(65,35,Mod-1),Mod) << endl;

}