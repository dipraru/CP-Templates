#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Node
{
    int lo, hi, L, R, st;
};
struct WaveletTree
{
    vector<ll> val;
    vector<Node> t;
    vector<int> b;
    vector<ll> pref;
    int n = 0, D = 0, root = -1;
    int build(vector<int>& a, vector<int>& tmp, int L, int R, int lo, int hi)
    {
        int id = t.size();
        t.push_back({lo, hi, -1, -1, -1});
        if (lo == hi) return id;
        int mid = (lo+hi)>>1;
        int len = R - L,st = b.size();
        t[id].st = st;
        b.resize(st + len + 1);
        pref.resize(st + len + 1);
        b[st] = pref[st] = 0;
        for (int i = 0; i < len; i++)
        {
            int x = a[L + i];
            b[st + i + 1] = b[st + i] + (x <= mid);
            pref[st + i + 1] =pref[st + i] + val[x];
        }
        int leftCnt = b[st + len];
        int lp = 0, rp = leftCnt;
        for (int i = L; i < R; i++)
        {
            if (a[i] <= mid) tmp[lp++] = a[i];
            else tmp[rp++] = a[i];
        }
        copy(tmp.begin(), tmp.begin()+len, a.begin() + L);
        t[id].L= build(a, tmp, L, L + leftCnt, lo, mid);
        t[id].R = build(a, tmp, L + leftCnt, R, mid + 1, hi);
        return id;
    }

    void mapped(int id, int l, int r, int& lb, int& rb) 
    {
        int st = t[id].st;
        lb = b[st + l - 1];
        rb = b[st + r];
    }

    ll kthRank(int id, int l, int r, int k)
    {
        Node& cur = t[id];
        if (cur.lo == cur.hi) return cur.lo;
        int lb, rb;
        mapped(id, l, r, lb, rb);
        int inLeft = rb - lb;
        if (k <= inLeft) return kthRank(cur.L, lb + 1, rb, k);
        return kthRank(cur.R, l - lb, r - rb, k - inLeft);
    }

    int countRankLess(int id, int l, int r, int q)
    {
        Node& cur = t[id];
        if (l > r || cur.lo >= q) return 0;
        if (cur.hi < q) return r - l + 1;
        int lb, rb;
        mapped(id, l, r, lb, rb);
        return countRankLess(cur.L, lb + 1, rb, q)+ countRankLess(cur.R, l - lb, r - rb, q);
    }

    int countRankEqual(int id, int l, int r, int rank)
    {
        Node& cur = t[id];
        if (l > r || rank < cur.lo || rank > cur.hi) return 0;
        if (cur.lo == cur.hi) return r - l + 1;
        int mid = cur.lo + (cur.hi - cur.lo) / 2;
        int lb, rb;
        mapped(id, l, r, lb, rb);
        if (rank <= mid) return countRankEqual(cur.L, lb + 1, rb, rank);
        return countRankEqual(cur.R, l - lb, r - rb, rank);
    }

    ll sumRankLess(int id, int l, int r, int q)
    {
        Node& cur = t[id];
        if (l > r || cur.lo >= q) return 0;
        if (cur.hi < q)
        {
            if (cur.lo == cur.hi) return val[cur.lo] * (r - l + 1LL);
            int st = cur.st;
            return pref[st + r] - pref[st + l - 1];
        }
        int lb, rb;
        mapped(id, l, r, lb, rb);
        return sumRankLess(cur.L, lb + 1, rb, q) + sumRankLess(cur.R, l - lb, r - rb, q);
    }

public:
    WaveletTree() = default;

    explicit WaveletTree(const vector<ll>& a)
    {
        n = a.size();
        if (n == 0) return;
        val=a;
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        D=val.size();
        int H = 0;
        while ((1LL << H) < D) H++;
        size_t cap = n * H + D - 1;
        t.reserve(2*D - 1);
        b.reserve(cap);
        pref.reserve(cap);
        vector<int> work(n), tmp(n);
        for (int i = 0; i < n; i++)
            work[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
        root = build(work, tmp, 0, n, 0, D - 1);
    }

    ll kth(int l, int r, int k)
    {
        if (root == -1 || l < 1 || r > n || l > r || k < 1 || k > r - l + 1) return -1;
        return val[kthRank(root, l, r, k)];
    }

    int countLTE(int l, int r, ll x)
    {
        if (root == -1 || l < 1 || r > n || l > r) return 0;
        int q = upper_bound(val.begin(), val.end(), x) - val.begin();
        return countRankLess(root, l, r, q);
    }

    int countEqual(int l, int r, ll x)
    {
        if (root == -1 || l < 1 || r > n || l > r) return 0;
        auto it = lower_bound(val.begin(), val.end(), x);
        if (it == val.end() || *it != x) return 0;
        int rank = it - val.begin();
        return countRankEqual(root, l, r, rank);
    }

    ll sumLess(int l, int r, ll x)
    {
        if (root == -1 || l < 1 || r > n || l > r) return 0;
        int q = lower_bound(val.begin(), val.end(), x) - val.begin();
        return sumRankLess(root, l, r, q);
    }

    ll rangeSum(int l, int r)
    {
        if (root == -1 || l < 1 || r > n || l > r) return 0;
        if (D == 1) return val[0] * (r - l + 1LL);
        int st = t[root].st;
        return pref[st + r] - pref[st + l - 1];
    }
};

int main()
{
    
}