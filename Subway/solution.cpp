#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
#define REP(i,a,b) for (int i=a; i<=b; i++)
#define REPR(i,a,b) for (int i=a; i>=b; i--)
#define fa(i,v) for (auto i: v)
#define all(c) c.begin(), c.end()
#define sz(x) ((int)((x).size()))
#define what_is(x) cerr << #x << " is " << x << " ";
#define F first
#define S second
#define pb push_back
#define eb emplace_back

inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    for (;!isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x * f;
}

const int MAXN = 2e5 + 5;

struct node {
    int ne,to;
} e[MAXN << 1];

int nume, n, x,y, b[MAXN], he[MAXN], curMin;
vi res;
inline void addside(int u,int v) {
    e[++nume].ne = he[u]; e[nume].to = v; he[u] = nume;
}

void dfs(int u, int pre) {
    for (int i = he[u]; i; i = e[i].ne) {
        int v = e[i].to, w = abs(v);
        if (w!=pre) {
            dfs(w, u);
            b[u]+= b[w] + (v<0);
        }
    }
}

void dfs2(int u, int pre) {
    for (int i = he[u]; i; i = e[i].ne) {
        int v = e[i].to, w = abs(v);
        if (w!=pre) {
            b[w] = b[u] + (v>0?1:-1);
            if (b[w]==curMin)
                res.pb(w);
            else if (b[w]<curMin)
                curMin = b[w],
                res.clear(),
                res.pb(w);
            dfs2(w, u);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    n = read();
    REP(_, 1, n-1) {
        x = read(), y = read();
        addside(x, y);
        addside(y, -x);
    }
    dfs(1, 1);
    curMin = b[1];
    res.pb(1);
    dfs2(1, 1);
    cout << curMin << endl;
    sort(all(res));
    fa(i, res) cout << i << " ";
}
