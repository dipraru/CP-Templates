#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
struct SegmentTree {
  vector<T> t;
  int n;
  T identity = T();
  SegmentTree(int _n) : n(_n) {
    int lg = 31 - __builtin_clz(n);
    if ((1 << lg) < n) lg++;
    lg++;
    t.assign((1 << lg) + 5, identity);
  }
  void update(int x, int lx, int rx, int p, T v) {
    if (lx == rx) {
      t[x] = v;
      return;
    }
    int mx = (lx + rx) >> 1;
    if (p <= mx) update(x << 1, lx, mx, p, v);
    else update(x << 1 | 1, mx + 1, rx, p, v);
    t[x] = merge(t[x << 1], t[x << 1 | 1]);
  }
  void update(int p, T v) {
    update(1, 1, n, p, v);
  }
  T query(int x, int lx, int rx, int l, int r) {
    if (lx > r || l > rx || r<l) return identity;
    if (l <= lx && r >= rx) return t[x];
    int mx = (lx + rx) >> 1;
    return merge(query(x << 1, lx, mx, l, r), query(x << 1 | 1, mx + 1, rx, l, r));
  }
  T query(int l, int r) {
    return query(1, 1, n, l, r);
  }
};
struct Node {
  long long a;
  Node()  { a = 0; }
  Node(ll _a) { a = _a; }
  friend Node merge(Node A, Node B) {
    return Node(max(A.a,B.a));
  }
};
int main()
{
    ll n,q;
    cin >> n >> q;
    int arr[n+1];
    SegmentTree<Node> s(n);
    for(int i=1;i<=n;i++) cin >> arr[i], s.update(i,Node(arr[i])) ;
    while(q--)
    {
        int op,l,r;
        cin >>l >> r;
        cout << s.query(l,r).a << '\n';
    }
}
