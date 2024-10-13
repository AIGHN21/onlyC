//Must become an expert in one's field
//Nothing in this world can take the place of persistence.
//Talent will not: nothing is more common than unsuccessful men with talent.
//Genius will not: unrewarded genius is almost a proverb.
//Education will not: the world is full of educated derelicts.
//Persistence and determination alone are omnipotent.
#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define ll long long
#define ull unsigned long long
#define ii pair<int, int>
#define maxn 200005
#define fr front
#define re rear
#define fi first
#define se second
#define inf 1000000007
struct point{
	int x, y, z;
	point(int _x, int _y, int _z):x(_x), y(_y), z(_z){};
};
int n, k;
vector<point> a;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back(point(x, y, z));
	}
	int ans = k * 3;
	for (int i = 1; i <= k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			if (a[i].x == a[j].x || a[i].y == a[j].y || a[i].z == a[j].z) ans --;
		}
	}
	cout << ans << el;
	return 0;
}
