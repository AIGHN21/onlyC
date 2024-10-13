#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// Cây phân đoạn chỉ cần khoảng 4 * n phần tử
vector<ll> T(400005);
vector<ll> arr(100005);
vector<ll> customer(100005);
ll n;

void update(int id, int l, int r, int i, int val) {
    // i nằm ngoài đoạn [l, r], ta bỏ qua
    if (i < l || i > r) return;

    // Nếu là lá thì cập nhật giá trị
    if (l == r) {
        T[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, i, val);
    update(2 * id + 1, mid + 1, r, i, val);

    // Cập nhật giá trị nút hiện tại sau khi các nút con đã được cập nhật
    T[id] = max(T[2 * id], T[2 * id + 1]);
}

void build(ll id, ll l, ll r) {
    if (l == r) {
        T[id] = arr[l];
        return;
    }
    ll mid = (r + l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    T[id] = max(T[id * 2], T[id * 2 + 1]);
}

ll getMax(ll id, ll l, ll r, ll room) {

    if (l == r) {
        update(1, 1, n, l, T[id] - room);
        arr[l] = arr[l] - room;  // Cập nhật số phòng còn lại
        return l;
    }

    if (T[id] < room) {
        return 0;
    }

    ll mid = (r + l) / 2;
    ll left = T[id * 2];

    if (left >= room) {
        return getMax(id * 2, l, mid, room);
    } else {
        return getMax(id * 2 + 1, mid + 1, r, room);
    }
}

int main() {
    ll t;
    cin >> n >> t;

    // Nhập số phòng
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Nhập số khách hàng
    for (ll i = 1; i <= t; i++) {
        cin >> customer[i];
    }

    // Xây dựng cây phân đoạn
    build(1, 1, n);

    // Trả lời các truy vấn của khách hàng
    for (ll i = 1; i <= t; i++) {
        cout << getMax(1, 1, n, customer[i]) << "\n";
    }

    return 0;
}
