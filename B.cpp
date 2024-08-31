#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<ll> towers;
    for (ll i = 0; i < n; ++i) {
        ll brick = arr[i];
        auto it = lower_bound(towers.begin(), towers.end(), brick);
        if (it == towers.end()) {
            towers.push_back(brick);
        } else {
            *it = brick;
        }
    }
    cout << towers.size() <<'\n';
    return 0;
}
