#include <bits/stdc++.h>
using namespace std;

// Adjust SZ to be >= (max_index + 1). Keep it as a power of two if you like.
const int SZ = 1<<17;

template<class T>
struct Node {
    T val = 0;
    T lazy = 0; 
    Node* left=nullptr;
    Node* right=nullptr;

    ~Node() {
        delete left;
        delete right;
    }
    void apply(int st, int en, T add) {
        val += add * (en - st + 1);
        lazy += add;
    }
    void push(int st, int en) {
        if (lazy == 0 || st == en) return;
        int mid = (st + en) >> 1;
        if (!left) left = new Node();
        if (!right) right = new Node();
        left->apply(st, mid, lazy);
        right->apply(mid+1, en, lazy);
        lazy = 0;
    }
    void pull() {
        val = 0;
        if (left) val += left->val;
        if (right) val += right->val;
    }

    void update(int st, int en, int l, int r, T add) {
        if (r < st || en < l) return;
        if (l <= st && en <= r) {
            apply(st, en, add);
            return;
        }
        push(st, en);
        int mid = (st + en) >> 1;
        if (l <= mid) {
            if (!left) left = new Node();
            left->update(st, mid, l, r, add);
        }
        if (r > mid) {
            if (!right) right = new Node();
            right->update(mid+1, en, l, r,add);
        }
        pull();
    }
    void update(int l, int r, int val){update(0,SZ-1,l,r,val);}
    T query(int st, int en, int l, int r) {
        if (r < st || en < l) return T(0);
        if (l <= st && en <= r) return val;
        push(st, en);
        int mid = (st + en) >> 1;
        T res = 0;
        if (left) res += left->query(st, mid, l, r);
        if (right) res += right->query(mid+1, en, l, r);
        return res;
    }
    T query(int l, int r){return query(0,SZ-1,l,r);}
};

int main() {
    Node<int> st;
    st.update(1,5,10);
    st.update(4, 7, 2);
    st.update(5,5,-2);
    cout << st.query(4,5) << '\n';
    int n;
    cin >> n;
    cout << n << '\n';
    return 0;
}