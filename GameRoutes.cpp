#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const ll maxn = 1e5 + 7;
const ll maxm = 2e5 + 7;
const ll MOD = 1e9 + 7;
ll visited[maxn] = {0}, dp[maxn] = {0}, n, m;
vector<ll> adj[maxn];

ll check(ll current) {
    if (current == 1) {
        visited[current] = 1;
        return 1;
    }

    if (!visited[current]) {
        for (ll val : adj[current]) {
            if (!visited[val]) {
                dp[val] = check(val) % MOD;
            }
            dp[current] = (dp[current] + dp[val]) % MOD;
        }
        visited[current] = 1;
    }

    return dp[current] % MOD;
}

int main() {
    IO
    cin >> n >> m;

    vector<pair<ll, ll>> arr(m + 1);
    dp[1] = 1;
    for (ll i = 1; i <= m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (ll i = 1; i <= m; i++) {
        adj[arr[i].second].push_back(arr[i].first);
    }

    ll ans = 0;

    for (ll val : adj[n]) {
        ans = (ans + check(val)) % MOD;
    }

    cout << ans << ln;
    return 0;
}
