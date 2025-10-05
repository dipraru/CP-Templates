#include<bits/stdc++.h>
using namespace std;

const long long int N=505, INF=1e18;
long long d[N][N];

int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) d[i][j]=INF;
    for(int i=0;i<=n;i++) d[i][i]=0;
    for(long long int u,v,w,i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        d[u][v]=d[v][u]=min(d[u][v],w);//Undirected Graph
    }
    for(int k=1;k<=n;k++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++) d[u][v]=min(d[u][k]+d[k][v], d[u][v]);
    for(int u,v,i=0;i<q;i++)
    {
        cin >> u >> v;
        cout << (d[u][v]==INF?-1:d[u][v]) << endl;
    }
}
