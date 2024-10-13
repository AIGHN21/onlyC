#include<iostream>
using namespace std;

#define maxn 10000000
#define ll long long

ll n, q, t;
ll st[maxn * 4], arr[maxn];

void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if (l == r && l == pos) {
        st[id] = val;
        arr[l] = val;
        return;
    }
    if (r < pos || l > pos) {
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];  // Chỉ một phép gán
}

int getSum(ll id, ll l, ll r, ll u, ll v) {
    if (u > r || v < l) {
        return 0;
    }
    if (l >= u && r <= v) {
        return st[id];
    }
    if(l==r && l>=u && l<=r){
        return st[id];
    }
    ll mid = (l + r) / 2;
    return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    cin >> n>> q;
    arr[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    // for (ll i = 1; i <= 2*n; i++) {
    //    cout<<st[i]<<" ";
    // }
    // cout << getSum(1, 1, n, 1, 4) << endl;
    // cout<<"\n";
    
    while (q--) {
        cin >> t;
        if (t == 1) {
            ll k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        } else if(t==2){
            ll a, b;
            cin >> a >> b;
            cout << getSum(1, 1, n, a, b) << endl;
        }
    }
    return 0;
}
