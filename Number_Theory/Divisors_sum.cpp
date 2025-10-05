#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;//Highest 1e7(not 2e7)
bool prime[N]{};
int sum[N];
void sieve(int n)//O(nlogn)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i) prime[j]=0, sum[j]+=i;
    }
}
int main()
{
    sieve(100);

}