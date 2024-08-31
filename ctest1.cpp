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
    vector<pair<ll, ll>> task(n);
    vector<ll> endTimes;
    for(int i = 0; i < n; i++) {
        cin >> task[i].first >> task[i].second;
        endTimes.push_back(task[i].second + 1);
    }
    sort(task.begin(), task.end(), [](pair<ll, ll>& a, pair<ll, ll>& b) {
        if (a.first == b.first) {
            return a.second < b.second; 
        }
        return a.first < b.first; 
    });
    
    vector<ll> queueList;
    ll maxMines = 0;
    
    for(const auto& t : task) {
        auto it = upper_bound(queueList.begin(), queueList.end(), t.first);
        if (it != queueList.begin()) {
            it = it-1;
            *it = t.second + 1;
        } else {
            queueList.push_back(t.second + 1);
            ++maxMines;
        }
        maxMines = max(maxMines, (ll)queueList.size());
    }
    
    cout << maxMines << endl;
    
    return 0;
}
