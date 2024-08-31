#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lower_bound(const vector<int>& arr, int value) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int upper_bound(const vector<int>& arr, int value) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
    }
    sort(items.begin(), items.end());

    vector<pair<int, int>> querys(m);
    for (int i = 0; i < m; ++i) {
        cin >> querys[i].first >> querys[i].second;
    }

    for (const auto& query : querys) {
        int x = query.first;
        int k = query.second;
        int lower_limit = x - k;
        int upper_limit = x + k;

        int low_id = lower_bound(items, lower_limit);
        int high_id = upper_bound(items, upper_limit);

        long long total_value = 0;
        for (int i = 0; i < low_id; ++i) {
            total_value += items[i];
        }
        for (int i = high_id; i < items.size(); ++i) {
            total_value += items[i];
        }

        items.erase(items.begin() + high_id, items.end());
        items.erase(items.begin(), items.begin() + low_id);
        cout << total_value << endl;
    }

    return 0;
}
