#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
const int N=1e6+2;
vector<pair<int,int>> g[N];
int vis[N];
vector<int> path;
//if all even degree, anyone can be starting.
//otherwise at most 2 can be odd degree and one of them stating and another ending

//removing edges
void dfs(int src)
{
    while(!g[src].empty())
    {
        auto it=g[src].back();
        g[src].pop_back();
        if(vis[it.second]) continue;
        vis[it.second]=1;
        dfs(it.first);
    }
    path.push_back(src);
}

//using extra pointer for indexing
int ptr[N];
void dfs2(int src)
{
    for(;ptr[src]<g[src].size();ptr[src]++)
    {
        auto it=g[src][ptr[src]];
        if(vis[it.second]) continue;
        vis[it.second]=1;
        dfs2(it.first);
    }
    path.push_back(src);
}

//using stack
void dfs3(int src)
{
    stack<int> st;
    st.push(src);
    while(!st.empty())
    {
        auto h=st.top();
        if(ptr[h]<g[h].size())
        {
            auto it=g[h][ptr[h]];
            ptr[h]++;
            if(vis[it.second]) continue;
            vis[it.second]=1;
            st.push(it.first);
        }
        else path.push_back(h),st.pop();
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++) vis[i]=0;
    for(int i=1;i<=n;i++) g[i].clear(), ptr[i]=0;
    path.clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
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