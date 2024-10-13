#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 301;
const ll INF = 1e15+1;
ll dist[maxn][maxn];
ll minFuel[maxn][maxn];
int main() {
    IO;
    ll n, m, L, q;
    cin >> n >> m >> L;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
   for (ll i = 0; i < m; ++i) {
        ll u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
     for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
        if (dist[i][j] <= L) {
                minFuel[i][j] = 0;
            } else {
                minFuel[i][j] = INF;
            }
            }
    }
    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                if (minFuel[i][k] != INF && minFuel[k][j] != INF) {
                    minFuel[i][j] = min(minFuel[i][j], minFuel[i][k] + minFuel[k][j] + 1);
                }
            }
        }
    }
    cin >> q;
    while (q--) {
        ll s, t;
        cin >> s >> t;
        if (minFuel[s][t] == INF) {
            cout << -1 << ln;
        } else {
            cout << minFuel[s][t] << ln;
        }
    }

    return 0;
}
