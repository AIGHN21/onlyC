#include <iostream>
#include <vector>
#include <algorithm>
#define line "\n"
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
void Solve() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), compare);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c >= v[i].first) {
            ans++;
            c += v[i].second;
        } else {
            break;
        }
    }
    
    cout << ans << line;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}