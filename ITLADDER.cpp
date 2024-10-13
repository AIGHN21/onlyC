#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const ll maxn = 1e5 + 7;
const ll MOD = 1e9 + 7;
using namespace std;

ll T[maxn * 4], lazy[maxn * 4], n, q, a, b, u, v;

void fix(ll id, ll l, ll r) {
    if (!lazy[id]) return;

    T[id] += lazy[id];
    cout<<"da cap nhap lazy tren doan tu "<<l<<" den "<<r<<" voi gia tri la "<<lazy[id]<<"\n";
    cout<<" t[id] = "<<T[id]<<"\n";

    if (l != r) {
        ll mid = (l + r) / 2;
        ll left_u_diff = mid - u;
        ll right_u_diff = r - u;
        ll left_l_diff = l - u;
        ll mid1_diff = mid + 1 - u;

        double value1 = (double)(left_u_diff - left_l_diff + 1) / 2;
        double value2 = (double)(right_u_diff - mid1_diff + 1) / 2;

        lazy[id * 2] += (ll)(value1 * (left_u_diff + left_l_diff)) * a + (left_u_diff - left_l_diff + 1) * b;
        lazy[id * 2 + 1] += (ll)(value2 * (right_u_diff + mid1_diff)) * a + (right_u_diff - mid1_diff + 1) * b;
    }
    cout<<" t[id]2 = "<<T[id]<<"\n";
    lazy[id] = 0;
}

void update(ll id, ll l, ll r) {

    if (l > v || r < u) return;

    if (l >= u && r <= v) {
        lazy[id] += (ll)(((double)((r - u) - (l - u) + 1) / 2) * ((r - u) + (l - u))) * a + ((r - u) - (l - u) + 1) * b;
        fix(id, l, r);
        return;
    }
    fix(id, l, r);
    ll mid = (l + r) / 2;
    update(id, l, mid);
    update(id, mid + 1, r);
    T[id] = T[id * 2] + T[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll x, ll y) {

    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return T[id];
    fix(id, l, r);
    ll mid = (l + r) / 2;
    return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
}

int main() {
    IO
    cin >> n >> q;
    while (q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            cin >> u >> v >> a >> b;
            update(1, 1, n);
            cout<<T[1]<<"\n";
        } else {
            ll x, y;
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << ln;
        }
    }

    return 0;
}
