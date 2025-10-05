#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> g[N];
vector<bool> vis(N,0);
bool flag=0;
void dfs(int src,int pre)
{
    if(flag || vis[src]) return;
    vis[src]=1;
    for(auto it:g[src])
    {
        if(vis[it] && it!=pre){
            flag=1;
            return;
        }
        dfs(it,src);
        if(flag) return;
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int u,v, i=0;i<e;i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dfs(i,0);
    if(flag) cout << "Cycle Exist" << endl;
    else cout << "No Cycle" << endl;
}