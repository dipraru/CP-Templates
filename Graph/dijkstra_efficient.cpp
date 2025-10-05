#include<bits/stdc++.h>
using namespace std;
// 1-> 2,1,
// 2-> 1,1
const int N=1e5+5;
int n,e;
vector<pair<int,int>> adj_list[N];
bool vis[N]={0};
vector<long long int> dis(N,1e18);
int parent[N];
void dijkstra(int src)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int selected_node=p.second;
        if(vis[selected_node]) continue;
        vis[selected_node]=1;
        for(auto it:adj_list[selected_node])
        {
            int child=it.first;
            int wt=it.second;
            if(dis[selected_node]+wt<dis[child]) 
            {
                dis[child]=dis[selected_node]+wt;
                pq.push({-dis[child], child});
                parent[child]=selected_node;
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    
    int u,v,w;
    for(int i=0;i<e;i++)
    {
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
        adj_list[v].push_back({u,w});
    }
    int src=1;
    dijkstra(1);
    if(!vis[n])
    {
        cout << -1 << endl;
        return 0;
    }
    int cur=n;
    stack<int> ans;
    while(1)
    {  
        ans.push(cur);
        if(cur==1) break;
        cur=parent[cur];
    }
    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
    cout << endl;
}