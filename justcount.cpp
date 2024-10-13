#include <iostream>
#include <vector>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define MOD 1000000007 // Giá trị chia dư

using namespace std;

void Solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0)));
    vector<vector<vector<ll>>> prefixsum(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, 0)));

    // Khởi tạo giá trị cho dp và prefixsum
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            dp[i][j][1] = 1;  // Mỗi ô có thể có 1 cách để tô màu đen
            prefixsum[i][j][1] = dp[i][j][1]
                                + (i > 1 ? prefixsum[i - 1][j][1] : 0)
                                + (j > 1 ? prefixsum[i][j - 1][1] : 0)
                                - (i > 1 && j > 1 ? prefixsum[i - 1][j - 1][1] : 0);
            // Chia dư cho MOD
            prefixsum[i][j][1] %= MOD;
        }
    }

    // Tính toán dp và prefixsum cho x > 1
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            for (ll x = 2; x <= k; x++) {
                if (i - 2 >= 1) {
                    dp[i][j][x] = (dp[i][j][x] + prefixsum[i - 2][m][x - 1]) % MOD; // Chia dư
                    if (m - j >= 2) {
                        dp[i][j][x] = (dp[i][j][x] + prefixsum[i - 1][m][x - 1]
                                        - prefixsum[i - 1][j + 1][x - 1]
                                        - prefixsum[i - 2][m][x - 1]
                                        + prefixsum[i - 2][j + 1][x - 1] + MOD) % MOD; // Chia dư
                    }
                }
                if (j - 2 >= 1) {
                    dp[i][j][x] = (dp[i][j][x] + prefixsum[i][j - 2][x - 1]) % MOD; // Chia dư
                    if (i - 2 >= 1) {
                        dp[i][j][x] = (dp[i][j][x] - prefixsum[i - 2][j - 2][x - 1] + MOD) % MOD; // Chia dư
                    }
                }
                prefixsum[i][j][x] = (dp[i][j][x]
                                    + (i > 1 ? prefixsum[i - 1][j][x] : 0)
                                    + (j > 1 ? prefixsum[i][j - 1][x] : 0)
                                    - (i > 1 && j > 1 ? prefixsum[i - 1][j - 1][x] : 0) + MOD) % MOD; // Chia dư
            }
        }
    }

    cout << prefixsum[n][m][k];
//
//    for (ll i = 1; i <= n; i++) {
//        for (ll j = 1; j <= m; j++) {
//            cout << dp[i][j][k] << " ";
//        }
//        cout << endl;
//    }
//    for (ll i = 1; i <= n; i++) {
//        for (ll j = 1; j <= m; j++) {
//            cout << prefixsum[i][j][2] << " ";
//        }
//        cout << endl;
//    }
}

int main() {
    IO
    Solve();
    return 0;
}
