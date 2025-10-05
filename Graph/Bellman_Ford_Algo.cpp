#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
const int N=1e5+10;
vector<pair<int,int>> adj_list[N];
int d[N];
int main()
{
    int n,m;
    cin >> n >> m;
    int parent[n+5]={0};
    for(int i=1;i<=n;i++) d[i]=INF;
    for(int u,v,w,i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
    }
    int src=1;
    d[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int node=1;node<=n;node++)
        {
            for(auto adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                if(d[v]>d[u]+w) d[v]=d[u]+w,parent[v]=u;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << d[i] << ' ';
    cout << endl;
    int dest=n;
    vector<int> ans;
    int cur=dest;
    while(1)
    {
        ans.push_back(cur);
        if(cur==src) break;
        cur=parent[cur];
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout << it << ' ';
    cout << endl;
}   