#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const ll maxn = 1e5+7;
vector<ll> adj[maxn];

void Solve() {
    bool fl = true;
    set<ll> groups[2];
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    groups[0].insert(1);
     for (ll i = 1; i <= n; i++) {
        cout << i << ": ";
        for (ll x : adj[i]) {
            cout << x << " ";
        }
        cout << ln;
    }
    for (ll i = 2; i <= n; i++) {
        bool tontai = false;
        for (ll ver : adj[i]) {
            if (groups[0].find(ver) != groups[0].end()) {
                tontai = true;
                break;
            }
        }

        if (!tontai) {
            groups[0].insert(i);
        } else {
            for (ll ver : adj[i]) {
                if (groups[1].find(ver) != groups[1].end()) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                groups[1].insert(i);
            }
        }
    }

    if (!fl) {
        cout << "IMPOSSIBLE";
    } else {
        for (ll i = 1; i <= n; i++) {
            if (groups[0].find(i) != groups[0].end()) {
                cout << 1 << " ";
            } else {
                cout << 2 << " ";
            }
        }
    }
}

int main() {
    IO
    Solve();
    return 0;
}
