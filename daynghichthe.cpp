#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll MAX_VAL = 60000;
const ll maxn = MAX_VAL + 6;
ll TsTree[maxn * 4], n;
ll arr[maxn];
void updateTS(ll id, ll l, ll r, ll pos) {
    if (l == r) {
        TsTree[id] += 1;
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid) {
        updateTS(id * 2, l, mid, pos);
    } else {
        updateTS(id * 2 + 1, mid + 1, r, pos);
    }
    TsTree[id] = TsTree[id * 2] + TsTree[id * 2 + 1];
}
ll getTs(ll id, ll l, ll r, ll u, ll v) {
    if (r < u || l > v) {
        return 0;
    }
    if (l >= u && r <= v) {
        return TsTree[id];
    }
    ll mid = (l + r) / 2;
    return getTs(id * 2, l, mid, u, v) + getTs(id * 2 + 1, mid + 1, r, u, v);
}
int main() {
    IO
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += getTs(1, 1, MAX_VAL, arr[i] + 1, MAX_VAL);
        updateTS(1, 1, MAX_VAL, arr[i]);
    }

    cout << ans << ln;
    return 0;
}
