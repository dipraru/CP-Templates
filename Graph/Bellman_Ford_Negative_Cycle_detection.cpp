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
    int dest=n,selected_node;
    bool negative_cycle=false;
    for(int i=0;i<n;i++)
    {
        for(int node=1;node<=n;node++)
        {
            for(auto adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                if(d[v]>d[u]+w)
                {
                    d[v]=d[u]+w;
                    parent[v]=u;
                    if(i==n-1) negative_cycle=true,selected_node=v;
                }
            }
        }
    }
    if(negative_cycle) 
    {
        cout << "Graph has Negative Cycle" << endl;
        for(int i=0;i<n-1;i++)
            selected_node=parent[selected_node];
        int first_node=selected_node;
        vector<int> cycle;
        cycle.push_back(selected_node);
        while(1)
        {
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if(selected_node==first_node) break;
        }
        reverse(cycle.begin(),cycle.end());
        for(auto it:cycle) cout << it << ' ';
        cout << endl;
    }
    else
    {
        for(int i=1;i<=n;i++) cout << d[i] << ' ';
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
        cout << endl;
    }
}   