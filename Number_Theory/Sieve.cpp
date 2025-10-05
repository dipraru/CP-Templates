#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
bool prime[N]{};
vector<int> primes;
void sieve(int n)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(!prime[i]) continue;
        for(int j=i*i;j<=n;j+=i) prime[j]=0;
    }
    for(int i=0;i<=n;i++) if(prime[i]) primes.push_back(i);
}
int main()
{
    sieve(100);

}