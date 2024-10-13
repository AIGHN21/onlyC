#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define ln '\n'
#define ll long long
#define inf 1000000007
const ll maxn = 10001;
ll n, arr[maxn][maxn];
ll dx[] = {0, 0, -1, 1};
ll dy[] = {-1, 1, 0, 0};

int bfs(int k) {
    if (arr[1][1] < k)
        return 0;

    queue<pair<int, int>> qe; // Sử dụng pair<int, int>
    int vs[maxn][maxn]; // Mảng đánh dấu
    memset(vs, 0, sizeof(vs)); // Đầu tiên, khởi tạo mảng
    vs[1][1] = 1; // Đánh dấu đã thăm ô (1, 1)
    qe.push({1, 1}); // Đưa vào hàng đợi

    while (!qe.empty()) {
        pair<int, int> val = qe.front();
        qe.pop();

        for (int i = 0; i < 4; ++i) {
            int x = val.first + dx[i], y = val.second + dy[i];

            // Kiểm tra ranh giới và điều kiện
            if (x < 1 || x > n || y < 1 || y > n || vs[x][y] || arr[x][y] < k) {
                continue;
            }
            vs[x][y] = 1; // Đánh dấu ô đã thăm
            qe.push({x, y}); // Thêm ô vào hàng đợi
        }
    }
    return vs[n][n]; // Trả về kết quả
}

int solve2() {
    ll l = 1;
    ll r = 1000000000;
    ll ans = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (bfs(m)) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n; // Đọc kích thước n
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j]; // Nhập dữ liệu vào arr
        }
    }

    cout << solve2(); // In ra kết quả
    return 0;
}
