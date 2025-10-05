#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
const int N=1005;
int rec[1005][1005], val[1005][1005];
void solve()
{
    int n,q;
    cin >> n >> q;
    memset(val,0,sizeof(val));
    memset(rec,0,sizeof(rec));
    for(int i=0,h,x;i<n;i++) cin >> h >> x, val[h][x]+=h*x;
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++) rec[i][j]=rec[i-1][j]+rec[i][j-1]-rec[i-1][j-1]+val[i][j];
}
signed main()
{
    fast
    int t=1;
    cin >> t;
    for(cs=1;cs<=t;cs++)
    {
        //cout << "Case " << cs << ": "; 
        solve();
    }
    return 0;
}