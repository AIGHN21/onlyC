#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<int,int>> arr(n);
    unordered_map<ll,unordered_map<ll,ll>> mymap;
    unordered_map<ll,unordered_map<ll,ll>> contain;
    unordered_map<ll,unordered_map<ll,ll>> becontain;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0]>>arr[i][1];
        mymap[arr[i][0]][arr[i][1]]=i;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    for(int i = 0 ; i < n ; i++){
        for(int i = 0 ; i < )
    }
    return 0;
}