#include<bits/stdc++.h>
using namespace std;

bool flag=true;
const int N=1005;
int mark[N]={0};
vector<int> g[N];
stack<int> ans;
bool dfs(int src)
{
    if(!flag) return flag;
    mark[src]=1;
    for(auto child:g[src])
    {
        if(mark[child]==0) dfs(child);
        else if(mark[child]==1) flag=false;
    }
    ans.push(src);
    mark[src]=2;
    return flag;
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
        if(!mark[i] && !dfs(i))
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}