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
    
    vector<ll> arr(n), dp(k + 1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end()); 
    
    dp[0] = 1;
    
    for(ll i = 1; i <= k; i++){
        // Iterate over all coins
        for(ll j = 0; j < n; j++){
            if(arr[j] <= i){
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
            }
        }
    }
    
    cout << dp[k]; 
    return 0;
}
