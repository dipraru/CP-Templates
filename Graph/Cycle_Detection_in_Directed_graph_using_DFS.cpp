#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int mark[N]={0};
vector<int> g[N];
int cycle=0;
void dfs(int src)
{
    mark[src]=1;
    for(auto child:g[src])
    {
        if(mark[child]==1) cycle++;
        else if(mark[child]==0) dfs(child);
    }
    mark[src]=2;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(mark[i]==0) dfs(i);
    cout << (cycle==0?"NO":"YES") << endl;
}