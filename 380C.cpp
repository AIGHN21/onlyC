#include <iostream>
#include <vector>
using namespace std;
#define MAXN 10000
#define ll long long

struct bracke{
    ll value;
    ll open;
    ll close;
};

bracke T[MAXN*4];
string s;

void build(ll id, ll l, ll r) {
    if (l == r) {
        bracke br;
        br.open = (s[l-1] == '(') ? 1 : 0;
        br.close = (s[l-1] == ')') ? 1 : 0;
        br.value = 0;
        T[id] = br;
        return;
    }

    ll mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    bracke left = T[id * 2];
    bracke right = T[id * 2 + 1];

    ll match = min(left.open, right.close);
    bracke current;
    current.value = left.value + right.value + match;
    current.open = left.open + right.open - match;
    current.close = left.close + right.close - match;
    T[id] = current;
}

bracke getValue(ll id, ll l, ll r, ll u, ll v) {
    if (l > v || r < u) {
        return {0, 0, 0};
    }

    if (l >= u && r <= v) {
        return T[id];
    }

    ll mid = (l + r) / 2;
    bracke left = getValue(id * 2, l, mid, u, v);
    bracke right = getValue(id * 2 + 1, mid + 1, r, u, v);

    ll match = min(left.open, right.close);
    bracke result;
    result.value = left.value + right.value + match;
    result.open = left.open + right.open - match;
    result.close = left.close + right.close - match;

    return result;
}

int main() {
    cin >> s;
    ll t;
    cin >> t;
    build(1, 1, s.size());

    while (t--) {
        ll a, b;
        cin >> a >> b;
        bracke result = getValue(1, 1, s.size(), a, b);
        cout << result.value * 2 << "\n";
    }

    return 0;
}
