#include <iostream>
#include <vector>
#define ll long long
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
const int MOD = 1e9+7;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else {
        vector<ll> dp(n, 0);
        if (n < 7) {
            dp[0] = 1;
            for (int i = 1; i < n; i++) {
                dp[i] = dp[i - 1] * 2;
            }
            cout << dp[n - 1];
        } else {
            dp[0] = 1;
            dp[1] = 2;
            dp[2] = 4;
            dp[3] = 8;
            dp[4] = 16;
            dp[5] = 32;
            for (int i = 6; i < n; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6])%MOD;

            }
            cout << dp[n - 1];
        }
    }

    return 0;
}
