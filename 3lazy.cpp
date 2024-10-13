#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 200000;
ll T[maxn*4], lazy1[maxn*4], lazy2[maxn*4], arr[maxn], n, m;

void build(ll id, ll l, ll r) {
    if(l == r) {
        T[id] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    T[id] = T[id * 2] + T[id * 2 + 1];
}

void apply_lazy1(ll id, ll l, ll r) {
    if(lazy1[id] != 0) {
        T[id] += lazy1[id] * (r - l + 1);
        if(l != r) {
            if(!lazy2[id * 2]) {
                lazy1[id * 2] += lazy1[id];
            } else {
                lazy2[id * 2] += lazy1[id];
            }
            if(!lazy2[id * 2 + 1]) {
                lazy1[id * 2 + 1] += lazy1[id];
            } else {
                lazy2[id * 2 + 1] += lazy1[id];
            }
        }
        lazy1[id] = 0;
    }
}

void apply_lazy2(ll id, ll l, ll r) {
    if(lazy2[id]) {
        T[id] = lazy2[id] * (r - l + 1);
        if(l != r) {
            lazy2[id * 2] = lazy2[id];
            lazy2[id * 2 + 1] = lazy2[id];
            lazy1[id * 2] = lazy1[id * 2 + 1] = 0;
        }
        lazy2[id] = 0;
    }
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    apply_lazy2(id, l, r);
    apply_lazy1(id, l, r);
    if(l > v || r < u) {
        return 0;
    }
    if(l >= u && r <= v) {
        return T[id];
    }
    ll mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void update(ll id, ll l, ll r, ll u, ll v, ll val, int type) {
    apply_lazy2(id, l, r);
    apply_lazy1(id, l, r);

    if(l > v || r < u) {
        return;
    }
    if(l >= u && r <= v) {
        if(type == 1) {
            lazy1[id] += val;
            apply_lazy1(id, l, r);
        } else {
            lazy2[id] = val;
            apply_lazy2(id, l, r);
        }
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val, type);
    update(id * 2 + 1, mid + 1, r, u, v, val, type);
    T[id] = T[id * 2] + T[id * 2 + 1];
}

int main() {
    IO;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    ll a, b, val;
    while(m--) {
        int k;
        cin >> k >> a >> b;
        if(k == 1) {

        cin >> val;
        update(1, 1, n, a, b, val, 1);
    }
        else if(k == 2) {
        cin >> val;
        update(1, 1, n, a, b, val, 2);
    }
        else if(k == 3) {
        cout << get(1, 1, n, a, b) << "\n";
    }
    }
    return 0;
}
