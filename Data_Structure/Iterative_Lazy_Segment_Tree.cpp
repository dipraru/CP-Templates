#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll a;
  Node() : a(0) {}
  Node(ll _a) : a(_a) {}
  friend Node merge(const Node &A, const Node &B) {
    return Node(A.a + B.a);
  }
};
//0 indexed segment tree
struct SegmentTree {
  int n;
  int size;
  int height;
  vector<Node> t;
  vector<ll> lazy;
  vector<char> isLazy;
  vector<int> startIdx,endIdx;

  SegmentTree(int _n) { init(_n); }

  void init(int _n) {
    n = _n;
    size = 1;
    while (size < max(1, n)) size <<= 1;
    t.assign(2 * size, Node());
    lazy.assign(2 * size, 0);
    isLazy.assign(2 * size, 0);
    startIdx.assign(2 * size, 0);
    endIdx.assign(2 * size, 0);

    height = 0;
    for (int tmp = size; tmp > 1; tmp >>= 1) ++height;
    for (int i = size; i < 2 * size; ++i)
      startIdx[i] = i - size,endIdx[i] = i - size;
    for (int i = size - 1; i >= 1; --i)
      startIdx[i] = startIdx[i << 1],endIdx[i] = endIdx[i << 1 | 1];
  }

  void build(const vector<ll> &vals) {
    for (int i = 0; i < n; ++i) t[size + i] = Node(vals[i]);
    for (int i = n; i < size; ++i) t[size + i] = Node();
    for (int nd = size - 1; nd >= 1; --nd) pull(nd);
  }

  inline void pull(int nd) {
    t[nd] = merge(t[nd << 1], t[nd << 1 | 1]);
    if(isLazy[nd]) t[nd].a+=lazy[nd]*(endIdx[nd]-startIdx[nd]+1);
  }

  inline void apply_node(int nd, ll val) {
    t[nd].a += val * (endIdx[nd] - startIdx[nd] + 1);
    lazy[nd] += val;
    isLazy[nd] = 1;
  }

  inline void push(int nd) {
    if (!isLazy[nd] || nd >= size) return;
    apply_node(nd << 1, lazy[nd]);
    apply_node(nd << 1 | 1, lazy[nd]);
    lazy[nd] = isLazy[nd] = 0;
  }

  inline void pushAll(int p) {
    for (int s = height; s >= 1; --s)
      if (p>>s) push(p>>s);
  }

  void update(int l, int r, ll val) {
    if (l > r) return;
    l+=size, r+=size;
    pushAll(l),pushAll(r);
    int L0 = l, R0 = r;
    for(;l<=r;l>>=1, r>>=1) {
      if (l & 1) apply_node(l++, val);
      if (!(r & 1)) apply_node(r--, val);
    }
    for (int i = L0; i > 1; i >>= 1) pull(i >> 1);
    for (int i = R0; i > 1; i >>= 1) pull(i >> 1);
  }

  Node query(int l, int r) {
    if (l > r) return Node();
    l+=size, r+=size;
    pushAll(l),pushAll(r);
    Node resL = Node();
    Node resR = Node();
    for (; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) resL = merge(resL, t[l++]);
      if (!(r & 1)) resR = merge(t[r--], resR);
    }
    return merge(resL, resR);
  }

  void updatePoint(int p, ll v) {
    int leaf = p + size;
    pushAll(leaf);
    apply_node(leaf,v);
    for (int i = leaf; i > 1; i >>= 1) pull(i >> 1);
  }
};
