#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define float long double

template<typename T>
class MergeSortTree {
public:
    int n;
    vector<vector<T>> tree;

    void build(int node, int st, int en)
    {
        if(st==en) {tree[node].push_back(arr[st]);return;}
        int mid=(st+en)/2;
        build(2*node, st,mid);
        build(2*node+1,mid+1,en);
        merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
    }
    int query(int node, int st, int en, int l, int r)
    {
        if(st>r || en<l || st>en || r<l) return 0;
        if(st>=l && en<=r)
        {
            int len=tree[node].size();
            len-=(upper_bound(tree[node].begin(),tree[node].end(),r)-tree[node].begin());
            return len;
        }
        int mid=(st+en)/2;
        return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
    }
    MergeSortTree(const vector<T>& A) {
        n = int(A.size());
        if (n == 0) return;
        tree.resize(4 * n);
        build(1,1,n);
    }
    int query(int L, int R) {
        if (n == 0 || L > R || L < 1 || R > n) return 0;
        return queryRec(1,1,n,L,R);
    }
};

signed main()
{
    fast
    int n,q;
    cin >> n >> q;
}