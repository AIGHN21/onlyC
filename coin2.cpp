#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;
    cin >> n>>k;

    if (n < 3) {
        return 0;
    }

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(2, vector<ll>(n, 0));
    
    for (int i = 0; i < n-1; i++) {
        dp[0][i] = arr[i];
    }

    vector<ll> dpMax(1);
    dpMax[0] = arr[0];
    int mx = arr[0];
    for (int i = 1; i <= k-1; i++) {
        mx = max(arr[i-1],mx);
        dp[1][i] = mx+arr[i];
    }
    for (int i = k; i < n; i++) {
        ll maxV = arr[i-k];
        for(int j = i-1 ; j>i-k ; j--){
            maxV = max(arr[j],maxV);
        }
        dp[1][i] = maxV - arr[i];
    }
        ll ans = dp[1][0];
        for (int j = 1; j < n; j++) {
            ans= max(dp[1][j],ans);
        }
        cout <<ans;

    return 0;
}
