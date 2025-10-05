#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

int mob[N];
void mobius() {
    for(int i=0;i<N;i++) mob[i]=1;
    for(int i=2;i<N;i++)
        for(int j=2*i;j<N;j+=i)  mob[j]-=mob[i];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mobius();
    for(int i=1;i<=20;i++) cout << mob[i] << ' ';
    cout << '\n';
  return 0;
}
// https://codeforces.com/contest/547/problem/C