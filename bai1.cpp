#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1005;
int n;
int a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// Các hướng di chuyển: lên, xuống, trái, phải
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Hàm kiểm tra xem có thể đi từ (1,1) đến (n,n) với số lượng khách tối đa là m không
bool bfs(int m) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        auto edge = q.front();
        q.pop();

        if (edge.first == n && edge.second == n) return true; // Đến đích

        for (int i = 0; i < 4; ++i) {
            int nx = edge.first + dx[i];
            int ny = edge.first + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n &&
                !visited[nx][ny] && a[nx][ny] >= m) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

// Hàm chính để giải quyết bài toán
int solve() {
    int left = 1, right = 1e9, ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (bfs(mid)) {
            ans = max(ans, mid); // Cập nhật giá trị lớn nhất
            left = mid + 1; // Tìm kiếm nửa lớn hơn
        } else {
            right = mid - 1; // Tìm kiếm nửa nhỏ hơn
        }
    }

    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
