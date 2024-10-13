#include <iostream>
#include <vector>
#include<math.h>
#include <algorithm>
#include <queue>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const ll INF = 2000000000000000000LL;
using namespace std;

struct Edge {
    ll u,v,w;
// cạnh từ u đến v, trọng số w
};
void bellmanFord(ll n, ll S, vector<Edge> &e, vector<ll> &D) {
    // e: danh sách cạnh
    // n: số đỉnh
    // S: đỉnh bắt đầu
    // D: độ dài đường đi ngắn nhất
    // trace: mảng truy vết đường đi
    // INF nếu không có đường đi
    // -INF nếu có đường đi âm vô tận
  D.resize(n+1, INF);
//    trace.resize(n, -1);

    D[S] = 0;
    for(int T = 2; T <= n; T++) {
        for (auto E : e) {
            ll u = E.u;
            ll v = E.v;
            ll w = E.w;
            if (D[u] != INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
            }
        }
    }
    // sau khi chạy xong N-1 vòng lặp Bellman-Ford
    for(int T = 1; T <= n; T++){
    for (auto E : e) {
        int u = E.u;
        int v = E.v;
        long long w = E.w;
        if (D[u] != INF && D[v] > D[u] + w) {
            // vẫn còn tối ưu được --> âm vô cực
            D[v] = -INF;
        }
    }
    }
}

int main() {
    IO
    ll n, m;
    cin >> n >> m;
    vector<Edge> E(m + 1);
    vector<ll> D;

    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        w*=(ll)-1;
        E.push_back({u,v,w});
    }
    bellmanFord(n, 1,E,D);
    cout<<((D[n]==-INF)?-1:-D[n]);

    return 0;
}
