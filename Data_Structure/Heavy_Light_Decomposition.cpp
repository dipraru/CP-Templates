#include<bits/stdc++.h>
using namespace std;
struct HeavyLightDecomposition {
    struct SegmentTree {
        vector<long long> tree, lazy;
        int n;
        long long inf;
        SegmentTree(int size) : n(size) {
            tree.assign(4 * (n + 1), 0);
            lazy.assign(4 * (n + 1), 0);
            inf=1e18;
        }

        void propagate(int node, int start, int end) {
            if (lazy[node] != 0) {
                tree[node] = tree[node]+ lazy[node];
                if (start != end) {
                    lazy[node * 2] += lazy[node];
                    lazy[node * 2 + 1] += lazy[node];
                }
                lazy[node] = 0;
            }
        }

        void update(int node, int start, int end, int l, int r, long long value) {
            propagate(node, start, end);
            if (start > r || end < l) return;

            if (start >= l && end <= r) {
                lazy[node] += value;
                propagate(node, start, end);
                return;
            }

            int mid = (start + end) / 2;
            update(node * 2, start, mid, l, r, value);
            update(node * 2 + 1, mid + 1, end, l, r, value);

            tree[node] = max(tree[node * 2] , tree[node * 2 + 1]);
        }

        long long query(int node, int start, int end, int l, int r) {
            propagate(node, start, end);
            if (start > r || end < l) return -inf;

            if (start >= l && end <= r) return tree[node];

            int mid = (start + end) / 2;
            return max(query(node * 2, start, mid, l, r) ,
                   query(node * 2 + 1, mid + 1, end, l, r));
        }

        void update(int l, int r, long long value) {
            update(1, 1, n, l, r, value);
        }

        long long query(int l, int r) {
            return query(1, 1, n, l, r);
        }
    };

    vector<vector<int>> tree;
    vector<int> parent, depth, heavy, head, pos, subsize;
    SegmentTree segTree;
    int curPos;
    long long inf;
    HeavyLightDecomposition(int n)
        : tree(n + 1),
          parent(n + 1, -1),
          depth(n + 1, 0),
          heavy(n + 1, -1),
          head(n + 1),
          pos(n + 1),
          subsize(n + 1, 0),
          segTree(n),
          curPos(1),
          inf(1e18) {}

    void addEdge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int dfs(int u) {
        subsize[u] = 1;
        int maxSubtree = 0;

        for (int v : tree[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            int subtreeSize = dfs(v);
            subsize[u] += subtreeSize;
            if (subtreeSize > maxSubtree) {
                maxSubtree = subtreeSize;
                heavy[u] = v;
            }
        }
        return subsize[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = curPos++;
        if (heavy[u] != -1) decompose(heavy[u], h);

        for (int v : tree[u]) {
            if (v != parent[u] && v != heavy[u]) decompose(v, v);
        }
    }

    void init(int root = 1) {
        dfs(root);
        decompose(root, root);
    }

    void updatePath(int u, int v, long long value, bool isEdge = false) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            segTree.update(pos[head[u]], pos[u], value);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        segTree.update(pos[u] + isEdge, pos[v], value);
    }

    long long queryPath(int u, int v, bool isEdge = false) {
        long long result = -inf;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) swap(u, v);
            result =max(result, segTree.query(pos[head[u]], pos[u]));
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        result =max(result, segTree.query(pos[u] + isEdge, pos[v]));
        return result;
    }

    // Public API
    void updateVertexPath(int u, int v, long long value) {
        updatePath(u, v, value, false);
    }

    long long queryVertexPath(int u, int v) {
        return queryPath(u, v, false);
    }

    void updateEdgePath(int u, int v, long long value) {
        updatePath(u, v, value, true);
    }

    long long queryEdgePath(int u, int v) {
        return queryPath(u, v, true);
    }
     void updateSubtree(int u, long long value) {
        segTree.update(pos[u], pos[u] + subsize[u] - 1, value);
    }

    long long querySubtree(int u) {
        return segTree.query(pos[u], pos[u] + subsize[u] - 1);
    }
};
int main()
{
    
}