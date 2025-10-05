#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=4e5+2;
int fact[N], ifact[N], reciprocal[N];
 
struct comb_init {
  comb_init() {
    reciprocal[1] = 1;
    for (int i = 2; i < N; ++i) {
      reciprocal[i] = (MOD - MOD / i) * (long long)reciprocal[MOD % i] % MOD;
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = (long long)fact[i - 1] * i % MOD;
      ifact[i] = (long long)ifact[i - 1] * reciprocal[i] % MOD;
    }
  }
} comb_init_;
 
long long comb(long long n, long long m) {
  if (n < m || m < 0) return 0;
  return (long long)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}
signed main()
{
    int n,r;
    cin >> n >> r;
    cout << comb(n,r) << endl;
    int ncr[30][30];
    long long x=0;
    for(int i=0;i<16;i++) x+=comb(16,i);
    cout << x << '\n';
    cout << fact[16] << '\n';
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<i;j++)
        {
            ncr[i][j]=comb(i,j);
            cout << ncr[i][j] << ' ';
            
        }
    }
    cout << "fjs" << endl;
}