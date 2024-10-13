#include <iostream>
#include <vector>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const ll maxn = 1000;
ll n, q;

int main() {
    IO
    cin >> n >> q;


    vector<vector<char>> s(n + 1, vector<char>(n + 1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    vector<vector<ll>> prefixRow(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> prefixCol(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; i++) {
        prefixRow[i][1] = (s[i][1] == '*') ? 1 : 0;
        for (ll j = 2; j <= n; j++) {
            prefixRow[i][j] = ((s[i][j] == '*') ? 1 : 0) + prefixRow[i][j - 1];
        }
    }

    for (ll i = 1; i <= n; i++) {
        prefixCol[1][i] = prefixRow[1][i];
        for (ll j = 2; j <= n; j++) {
            prefixCol[j][i] = prefixRow[j][i] + prefixCol[j - 1][i];
        }
    }

    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;


        ll result = prefixCol[x2][y2];

        if (x1 > 1) {
            result -= prefixCol[x1 - 1][y2];
        }
        if (y1 > 1) {
            result -= prefixCol[x2][y1 - 1];
        }
        if (x1 > 1 && y1 > 1) {
            result += prefixCol[x1 - 1][y1 - 1];
        }

        cout << result << ln;
    }

    return 0;
}
