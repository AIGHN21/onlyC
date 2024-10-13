#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

int main(){
    IO
    ll n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    vector<ll> dp(n), ends(n);

    for(ll i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    dp[0] = arr[0].second - arr[0].first;
    ends[0] = arr[0].second;
    ll ans = dp[0]; // Khởi tạo ans bằng dp[0]

    for(ll i = 1 ; i < n ; i++){
        ll maxV = 0;
        for(ll j = i - 1; j >= 0 ; j--){
            if(dp[j] > maxV && ends[j] <= arr[i].first){
                maxV = dp[j];
            }
        }
        dp[i] = (arr[i].second - arr[i].first) + maxV;
        ends[i] = arr[i].second;
        ans = max(dp[i], ans); // Sửa cách viết
    }

    cout << ans;
    return 0;
}

