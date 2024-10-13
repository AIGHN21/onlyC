#include <iostream>
#include <vector>
#include <queue>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const ll maxn = 501;
const ll maxm = 250000;
const long long INF = 2000000000000000000LL;

struct Edge {
    ll v;
    ll w;
};
struct Node {
    ll u;
    ll Dist_u;
};

struct cmp {
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

void dijkstraSparse(ll n, ll s, vector<vector<Edge>> &E, vector<vector<long long>> &D) {
    D[s].resize(n + 1, INF);
    vector<bool> P(n + 1, false);
    D[s][s] = 0;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({s, D[s][s] });
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
            if (D[s][v] > D[s][u] + w) {
                D[s][v] = D[s][u] + w;
                pq.push({v, D[s][v]});
            }
        }
    }
}

int main() {
    ll n, m,q;
    cin >> n >> m>>q;
    vector<vector<Edge>> E(n + 1);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    vector<vector<ll>> D(n + 1, vector<ll>(n + 1, INF));
    for(ll i = 1; i<=n;i++){
        dijkstraSparse(n,i,E,D);
    }
   while (q--) {
        ll a, b;
        cin >> a >> b;
        if (D[a][b] == INF) {
            cout << -1 << ln;
        } else {
            cout << D[a][b] << ln;
        }
    }


}
