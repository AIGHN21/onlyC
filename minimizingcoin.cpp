#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    
    vector<ll> arr(n), dp(k + 1,INT32_MAX);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    sort(arr.begin(), arr.end()); 
    for (ll i = 1; i <= k; i++) {
        for (ll j = 0; j < n; j++) {
            if (arr[j] <= i && dp[i - arr[j]] != INT32_MAX) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    if (dp[k] == INT32_MAX) {
        cout << -1 ; 
    } else {
        cout << dp[k] ;
    }
    return 0;
}
=