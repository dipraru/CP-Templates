#include<bits/stdc++.h>
using namespace std;
const int M=1000;
vector<int> g[M+1];
vector<int> mark(M+1,0);
bool bfs(int src)
{
    mark[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto child:g[x])
        {
            if(!mark[child])
            {
                q.push(child);
                mark[child]=mark[x]^3;
            }
            else if(mark[child]==mark[x]) return false;
        }
    }
    return true;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << (bfs(0)?"YES":"NO") << endl;
}