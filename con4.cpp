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

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        x--; 
        y--;

        ll sum = 0;
        for (int i = x; i <= y; i++) {
            sum += arr[i];
        }

        ll maxL = 0, maxR = 0;
        if (x > 0) {
            ll curSum = 0;
            for (int i = x - 1; i >= 0; i--) {
                curSum += arr[i];
                maxL = max(maxL, curSum);
            }
        }
        if (y < n - 1) {
            ll curSum = 0;
            for (int i = y + 1; i < n; i++) {
                curSum += arr[i];
                maxR = max(maxR, curSum);
            }
        }

        cout << maxL + sum + maxR << endl;
    }

    return 0;
}
