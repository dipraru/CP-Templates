#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
const int N=1e4+5;
vector<int> g[N];
int timer;
int vis[N],dis[N],lo[N];
vector<pair<int,int>> ans;
void dfs(int src, int par)
{
    vis[src]=1,dis[src]=lo[src]=timer++;
    for(auto it:g[src])
    {
        if(it==par) continue;
        if(vis[it]) lo[src]=min(lo[src],dis[it]);
        else
        {
            dfs(it,src);
            lo[src]=min(lo[src],lo[it]);
            if(lo[it]>dis[src]) ans.push_back({min(it,src), max(it,src)});
        }
    }
}
void solve()
{
    ans.clear();
    int n,m;
    cin >> n;
    for(int i=0;i<=n;i++) g[i].clear(),vis[i]=dis[i]=lo[i]=0; 
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i,-1);
    cout << ans.size() << " critical links\n";
    for(auto it:ans) cout << it.first << " - " << it.second << '\n';
}
signed main()
{
    fast
    int t=1;
    cin >> t;
    for(cs=1;cs<=t;cs++)
    {
        timer=1;
        cout << "Case " << cs << ":\n"; 
        solve();
    }
    return 0;
}