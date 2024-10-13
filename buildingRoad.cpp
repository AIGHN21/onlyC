#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define for1(n) for(ll i = 1 ; i<= n ; i++)
using namespace std;

int m, n;
const ll maxn = 1e5+7;
const ll maxm = 2e5+7;

struct DSU {
    vector<ll> parent, sz;
    DSU(ll n) : parent(n), sz(n) {}

    void make_set(ll v) {
        parent[v] = v;
        sz[v] = 1;
    }

    ll find_set(ll v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void join_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main() {
    IO
    cin >> n >> m;
    DSU dsu(n+1);
    vector<pair<ll, ll>> arr(m+1);
    vector<pair<ll, ll>> rs;

    // Khởi tạo các tập hợp cho từng phần tử
    for (ll i = 1; i <= n; i++) {
        dsu.make_set(i);
    }

    // Đọc các cạnh
    for (ll i = 1; i <= m; i++) {
        cin >> arr[i].first >> arr[i].second;
        dsu.join_sets(arr[i].first, arr[i].second);
    }

    ll ans = 0;

    // Nối các tập chưa được nối
    for (ll i = 1; i <= n-1; i++) {
        if (dsu.find_set(i) != dsu.find_set(i+1)) {
            ans++;
            rs.push_back({i, i+1});
            dsu.join_sets(i, i+1);
        }
    }

    cout << ans << ln;
    for (auto val : rs) {
        cout << val.first << " " << val.second << ln;
    }

    return 0;
}
