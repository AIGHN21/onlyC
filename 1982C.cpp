#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void Solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);

    // Nhập mảng
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0, curr_sum = 0;
    ll left = 0; // Chỉ số bắt đầu của dãy con

    // Duyệt qua từng phần tử của mảng
    for (ll right = 0; right < n; right++) {
        curr_sum += arr[right]; // Cộng dần các phần tử

        // Nếu tổng vượt quá r, ta phải di chuyển left để thu nhỏ tổng lại
        while (curr_sum > r && left <= right) {
            curr_sum -= arr[left];
            left++;
        }

        // Nếu tổng nằm trong khoảng [l, r], tăng kết quả
        if (curr_sum >= l && curr_sum <= r) {
            ans = max(ans, right - left + 1); // Lưu kết quả tốt nhất
        }
    }

    cout << ans << "\n";
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        Solve();
    }

    return 0;
}
