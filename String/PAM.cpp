#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
const int MAXN=1005;
const int MAXC=26;
struct PAM {
    int next[MAXN][MAXC];
    int fail[MAXN];
    int cnt[MAXN];
    int num[MAXN];
    int len[MAXN];
    int S[MAXN];
    int last, n, p;

    int newnode(int l) {
        memset(next[p], 0, sizeof(next[p]));
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init() {
        p = 0;
        newnode(0); // placeholder to occupy index 0 (not used)
        newnode(-1); // node 1 : length -1
        newnode(0);  // node 2 : length 0
        last = 2;
        n = 0;
        S[0] = -1; // sentinel
        fail[1] = 1;
        fail[2] = 1;
    }

    int get_fail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }

    void add(char ch) {
        int c = ch - 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if (!next[cur][c]) {
            int now = newnode(len[cur] + 2);
            fail[now] = next[get_fail(fail[cur])][c];
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
    }

    // optional: to accumulate counts of occurrences
    void count() {
        for (int i = p - 1; i >= 1; --i) cnt[fail[i]] += cnt[i];
    }
};
signed main()
{
    fast
    
    return 0;
}