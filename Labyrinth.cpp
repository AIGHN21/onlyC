#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

const int maxn = 1e3+7;
const int maxm = 1e3+7;
char graph[maxn][maxm];
int mark[maxn][maxm], xstart, ystart, xend, yend;
int m, n;
bool flg = 0;

struct edge {
    char c;
    pair<ll, ll> egs;
    edge* prev;
};

edge edges[maxn][maxm];

bool validate(int a, int b) {
    return (a >= 1 && a <= n && b >= 1 && b <= m);
}

bool check(int current, int Columncurrent) {
    queue<pair<ll, ll>> q;
    q.push({current, Columncurrent});
    mark[current][Columncurrent] = 1;
    edges[current][Columncurrent].prev = nullptr;
    while (!q.empty() && !flg) {
        pair<ll, ll> current = q.front();
        q.pop();
        ll x = current.first;
        ll y = current.second;

        if (validate(x-1, y) && graph[x-1][y] != '#' && mark[x-1][y] == 0) {
            q.push({x-1, y});
            edges[x-1][y] = {'U', {x-1, y}, &edges[x][y]};
            mark[x-1][y] = 1;
            if (graph[x-1][y] == 'B') {
                xend = x-1;
                yend = y;
                flg = 1;
                break;
            }
        }

        if (validate(x+1, y) && graph[x+1][y] != '#' && mark[x+1][y] == 0) {
            q.push({x+1, y});
            edges[x+1][y] = {'D', {x+1, y}, &edges[x][y]};
            mark[x+1][y] = 1;
            if (graph[x+1][y] == 'B') {
                xend = x+1;
                yend = y;
                flg = 1;
                break;
            }
        }

        if (validate(x, y-1) && graph[x][y-1] != '#' && mark[x][y-1] == 0) {
            q.push({x, y-1});
            edges[x][y-1] = {'L', {x, y-1}, &edges[x][y]};
            mark[x][y-1] = 1;
            if (graph[x][y-1] == 'B') {
                xend = x;
                yend = y-1;
                flg = 1;
                break;
            }
        }

        if (validate(x, y+1) && graph[x][y+1] != '#' && mark[x][y+1] == 0) {
            q.push({x, y+1});
            edges[x][y+1] = {'R', {x, y+1}, &edges[x][y]};
            mark[x][y+1] = 1;
            if (graph[x][y+1] == 'B') {
                xend = x;
                yend = y+1;
                flg = 1;
                break;
            }
        }
    }
    return flg == 1;
}

void backtrack(ll x, ll y) {
    vector<char> path;
    edge* eg = &edges[x][y];
    ll ans = 0;
    while (eg->prev != nullptr) {
        path.push_back(eg->c);
        eg = eg->prev;
        ans++;
    }
    cout<<ans<<ln;
    reverse(path.begin(), path.end());
    for (char c : path) {
        cout << c;
    }
    cout << ln;
}

int main() {
    IO
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                xstart = i;
                ystart = j;
            }
        }
    }

    mark[xstart][ystart] = 1;
    if (check(xstart, ystart)) {
        cout << "YES" << ln;
        backtrack(xend, yend);
    } else {
        cout << "NO" << ln;
    }

    return 0;
}
