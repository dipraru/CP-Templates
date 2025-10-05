#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int64>> C(N+1, vector<int64>(N+1, 0));
    C[0][0] = 1;
    for(int n = 1; n <= N; ++n){
        C[n][0] = 1;
        C[n][n] = 1;
        for(int k = 1; k < n; ++k){
            C[n][k] = (C[n-1][k-1] + C[n-1][k]) % MOD;
        }
    }
    
}