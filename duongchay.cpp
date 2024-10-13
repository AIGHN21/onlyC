#include <iostream>
#include <vector>
#include <queue>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const long long INF = 2000000000000000000LL;

int main() {
    ll n, m;
    cin >> n >> m;

    // Ma trận trọng số và khoảng cách
    vector<vector<long long>> w(n + 1, vector<ll>(n + 1, INF));
    vector<vector<long long>> D(n + 1, vector<ll>(n + 1, INF));


    vector<ll> heights(n + 1);
    for (ll i = 1; i <= n; i++) {
        D[i][i] = 0;
        w[i][i] = 0;
        cin >> heights[i];
    }


    ll edge_count = n - 1;
    while (edge_count--) {
        ll a, b;
        cin >> a >> b;
        w[a][b] = w[b][a] = 1;
    }


    D = w;


    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (D[u][k] != INF && D[k][v] != INF) {
                    D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
                }
            }
        }
    }

    ll ans = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
                for(int k = u;k<=v;k++){

                if (heights[u] == m || heights[k] == m|| heights[v] == m) {
                ans += (D[u][v]+D[u][k]+D[k][v]) ;
            }
            }
        }
    }

    cout << ans << ln;

    return 0;
}
