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

const int MAXN = 3005;

int n, x, y, d[MAXN];
vi adj[MAXN], path;
bool vis[MAXN], ringroad[MAXN], found;

void dfs(int u, int pre) {
    path.pb(u);
    vis[u]=1;
    fa(v, adj[u])
    if (v!=pre) {
        if (found) continue;
        if (vis[v]) {
            found = 1;
            REPR(i, sz(path)-1, 0) {
                ringroad[path[i]] = 1;
                if (path[i]==v) break;
            }
        } else
            dfs(v, u);
    }
    path.pop_back();
}

void dfs2(int u, int pre) {
    fa(v, adj[u])
        if (!ringroad[v] and v!=pre)
            d[v] = d[u]+1, dfs2(v, u);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    REP(_, 1, n)
        cin >> x >> y, adj[x].pb(y), adj[y].pb(x);

    dfs(1, 1);

    REP(u, 1, n)
        if (ringroad[u])
            dfs2(u, u);

    REP(i, 1, n)
        cout << d[i] << " ";
}
