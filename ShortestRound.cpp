#include <iostream>
#include <vector>
#include <queue>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const ll maxn = 1e5 + 7;
const long long INF = 2000000000000000000LL;

struct Edge {
    ll v;  // Đỉnh đích
    ll w;  // Trọng số của cạnh
};

struct Node {
    ll u;       // Đỉnh hiện tại
    ll Dist_u;  // Khoảng cách từ đỉnh nguồn đến đỉnh hiện tại
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;  // So sánh khoảng cách để ưu tiên đỉnh có khoảng cách ngắn hơn
    }
};

void dijkstraSparse(ll n, ll s, vector<vector<Edge>> &E, vector<long long> &D) {
    D.resize(n + 1, INF);  // Khoảng cách từ đỉnh nguồn đến tất cả các đỉnh ban đầu là vô hạn
    vector<bool> P(n + 1, false);  // Biến đánh dấu để kiểm tra xem đỉnh đã được xử lý chưa
    D[s] = 0;  // Khoảng cách từ đỉnh nguồn đến chính nó là 0

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({s, D[s]});  // Đưa đỉnh nguồn vào hàng đợi

    while (!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        ll u = x.u;
        if (P[u])
            continue;
        P[u] = true;
        for (auto e : E[u]) {
            ll v = e.v;
            long long w = e.w;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                pq.push({v, D[v]});
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Edge>> E(n + 1);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
    }
    vector<ll> D;
    dijkstraSparse(n, 1, E, D);
    for (ll i = 1; i <= n; i++) {
        if (D[i] == INF) {
            cout << 0 << " ";  // Nếu không có đường đi, in "INF"
        } else {
            cout << D[i] << " ";  // In giá trị khoảng cách
        }
    }

    return 0;
}
