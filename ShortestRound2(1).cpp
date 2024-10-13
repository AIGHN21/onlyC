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
int main(){
    ll n,m,q,l;
        cin >> n >> m>> l;
        vector<vector<long long>> w(n+1,vector<ll>(n+1,INF));
        vector<vector<long long>> D(n+1,vector<ll>(n+1,INF));
        for(ll i=1;i<=n;i++){
            D[i][i]=0;
            w[i][i]=0;
        }
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);
        w[a][a]=0;
        w[b][b]=0;
        w[b][a]=min(w[b][a], c);
    }
    D = w;
    for (int k = 1; k <= n; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (D[u][v] > D[u][k] + D[k][v]) {
                    D[u][v] = D[u][k] + D[k][v];
                }
            }
        }
    }
    cin>>q;
    while(q--){
         ll a, b;
        cin >> a >> b;
        if (D[a][b] == INF) {
            cout << -1 << ln;
        } else {
            cout << D[a][b] << ln;
        }
    }
}
