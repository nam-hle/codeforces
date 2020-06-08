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

const int MAXN = 1005;

int n,k,x, a[MAXN][5], ind[MAXN][5], d[MAXN],res;
vi adj[MAXN];

int dfs(int u) {
    d[u] = 1;
    fa(v, adj[u])
        if (d[v])
            d[u] = max(d[u], d[v]+1);
        else
            dfs(v),
            d[u] = max(d[u], d[v]+1);
    res = max(res, d[u]);
    return d[u];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    REP(j, 0, k-1)
        REP(i, 1, n)
            cin >> x, ind[x][j] = i;

    REP(i, 1, n)
        REP(j, 1, n) {
            bool cmp = 1;
            REP(kk, 0, k-1)
                cmp &= ind[i][kk] < ind[j][kk];
            if (cmp) adj[i].pb(j);
        }

    REP(i, 1, n)
        if (!d[i])
            dfs(i);

    cout << res;
}
