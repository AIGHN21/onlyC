#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> couples(n);
    for (int i = 0; i < n; ++i) {
        cin >> couples[i].first >> couples[i].second;
    }

    sort(couples.begin(), couples.end(), compare);
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (const auto& couple : couples) {
        if (pq.empty() || pq.top() > couple.second) {
            pq.push(couple.second);
        } else {
            pq.pop();
            pq.push(couple.second);
        }
    }
    cout << pq.size() << endl;
    return 0;
}
