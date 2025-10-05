#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
int phi[M];
void totient(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main()
{
    //count all phi value from 1 to n
    int n=100;
    totient(n);
    for(int i=1;i<=10;i++) cout << phi[i] << ' ';
    cout << '\n';
}