#include <bits/stdc++.h>

using namespace std;

long long sumHeight(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, long long x, long long r) {
    long long total = 0;
    vector<int> sortedA = a;
    vector<int> sortedC = c;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedC.begin(), sortedC.end());
    auto itA = lower_bound(sortedA.begin(), sortedA.end(), x);
    if (itA != sortedA.end()) {
        int index = itA - sortedA.begin();
        for (int i = index; i < a.size(); i++) {
            total += b[i];
        }
    }
    auto itC = lower_bound(sortedC.begin(), sortedC.end(), r - x);
    if (itC != sortedC.begin()) {
        int index = itC - sortedC.begin();
        for (int i = index-1; i < c.size(); i++) {
            total += d[i];
        }
    }
    return total;
}

int main() {
    int r, m, n;
    cin >> r >> m >> n;

    vector<int> a(m), b(m), c(n), d(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    long long ketqua=0;
    for(int i = 1 ; i <= r ; i++){
        ketqua = max(ketqua,sumHeight(a,b,c,d,i,r));
    }
    cout << ketqua << endl;
    return 0;
}