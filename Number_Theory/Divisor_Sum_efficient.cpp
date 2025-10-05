#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
const int N=2e7+5;
int sum[N];
int hp[N];
void seive()
{
    for(int i=0;i<N;i++) hp[i]=i;
    for(int i=2;i<N;i++)
    {
        if(hp[i]==i)
        {
            for(int j=2*i;j<N;j+=i) hp[j]=i;
        }
    }
}
void Sum_of_Divisor()
{
    for(int i=1;i<N;i++) sum[i]=1;
    sum[1]=0;
    for(int i=2;i<N;i++)
    {
        int x=i;
        int prv=0,mul=1,sm=1;

        while(x>1)
        {
            if(hp[x]==prv) mul*=prv, sm+=mul;
            else if(prv!=0) sum[i]*=(sm+mul*prv),prv=hp[x],sm=mul=1;
            else prv=hp[x],mul=sm=1;
            x/=hp[x];
        }
        sum[i]*=(mul*prv+sm);
    }
}
signed main()
{
    fast
    seive();
    Sum_of_Divisor();
    for(int i=2;i<N;i++) sum[i]+=sum[i-1];
    while(1)
    {
        int n;
        cin >> n;
        if(n==0) break;
        cout << sum[n] << endl;
    }
    return 0;
}