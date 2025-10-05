#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool prime[N]{};
vector<int> divisors[N];
void sieve()//O(nlogn)
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i) prime[j]=0, divisors[j].push_back(i);
    }
}
int main()
{
    int k;
    cin >> k;
    sieve();
    cout << "fs" << endl;
}