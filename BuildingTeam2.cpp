#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 1e5 + 7;
vector<ll> adj[maxn];
vector<int> teams(maxn);
vector<int> visited(maxn);

bool dfs(ll v, int color) {
    int nextcolor = ((color == 1) ? 2 : 1);
    visited[v] = 1;
    teams[v] = color;
    for (ll ver : adj[v]) {
        if (!visited[ver]) {
            if (!dfs(ver, nextcolor)) {
                return false;
            }
        } else {
            if (teams[ver] == color) {
                return false;
            }
        }
    }
    return true;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//    for (ll i = 1; i <= n; i++) {
//        cout << i << ": ";
//        for (ll x : adj[i]) {
//            cout << x << " ";
//        }
//        cout << ln;
//    }
    bool flg = true;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            flg = dfs(i, 1);
            if (!flg) break;
        }
    }
    if (!flg) {
        cout << "IMPOSSIBLE" << ln;
    } else {
        for (ll i = 1; i <= n; i++) {
            cout << teams[i] << " ";
        }
        cout << ln;
    }
}

int main() {
    IO
    Solve();
    return 0;
}
