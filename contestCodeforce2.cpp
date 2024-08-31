#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int x, int y, vector<string> &v, int n) {
  if (x == 0) {

    return (x + 1 < 2) && (y - 1 >= 0) && (y + 1 < n) &&
           (v[x + 1][y - 1] == 'x') && (v[x + 1][y + 1] == 'x') &&
           (v[x][y - 1] == '.') && (v[x][y + 1] == '.') && v[x + 1][y] == '.';
  } else if (x == 1) {
    return x - 1 >= 0 && y + 1 < n && y - 1 >= 0 && v[x - 1][y + 1] == 'x' &&
           v[x - 1][y - 1] == 'x' && (v[x][y - 1] == '.') &&
           (v[x][y + 1] == '.') && v[x - 1][y] == '.';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v(2);
    for (auto &i : v)
      cin >> i;
    ll ans = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (check(i, j, v, n))
          ans++;
      }
    }
    cout << ans << "\n";
  }
}