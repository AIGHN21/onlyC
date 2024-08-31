#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    if (n < 3) {
        return 0;
    }

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(3, vector<ll>(n, 0));
    
    for (int i = 0; i < n-2; i++) {
        dp[0][i] = arr[i];
    }

    vector<ll> dpMax(2);
    dpMax[0] = arr[0];
    for (int i = 1; i < n-1; i++) {
        dpMax[0] = max(dpMax[0], dp[0][i-1]);
        dp[1][i] = dpMax[0] + arr[i];
    }

    dpMax[1] = dp[1][1];
    for (int i = 2; i < n; i++) {
        dpMax[1] = max(dpMax[1], dp[1][i-1]);
        dp[2][i] = dpMax[1] - arr[i];
    }
    
        ll ans = dp[2][0];
        for (int j = 1; j < n; j++) {
            ans= max(dp[2][j],ans);
        }
        cout <<ans;

    return 0;
}
