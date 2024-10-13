#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include <cstring>
using namespace std;

const ll maxn = 1000;
ll T[maxn][maxn * 4];
ll n, q;
vector<vector<char>> s(maxn + 1, vector<char>(maxn + 1));

void build(ll id, ll l, ll r, ll row) {
    if (l == r) {
        T[row][id] = (s[row][l] == '*') ? 1 : 0;
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid, row);
    build(id * 2 + 1, mid + 1, r, row);
    T[row][id] = T[row][id * 2] + T[row][id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v, ll row) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return T[row][id];

    ll mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v, row) + get(id * 2 + 1, mid + 1, r, u, v, row);
}

int main() {
    IO
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        build(1, 1, n, i);
    }

    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = 0;
        for (ll i = x1; i <= x2; i++) {
            ans += get(1, 1, n, y1, y2, i);
        }

        cout << ans << ln;
    }

    return 0;
}
