#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0)
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first < b.first;
    });
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (!pq.empty()) {
            pair<ll, ll> p = pq.top();
            if (p.second <= arr[i].first) {
                pq.pop();
                pq.push(arr[i]);
                ans++;
            } else if (k > 0) {
                pq.push(arr[i]);
                ans++;
                k--;
            }
        } 
        else {
            pq.push(arr[i]);
            ans++;
            k--;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
