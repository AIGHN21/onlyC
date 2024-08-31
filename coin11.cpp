#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll findP(ll target, ll index, const vector<ll>& dsu, const vector<ll>& arr) {
    if (index < 0) {
        return -1;
    }
    
    ll k = dsu[index];
    if (arr[k] < target) {
        return k;
    } else {
        return findP(target, k, dsu, arr); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr(n), dsu(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dsu[0]=-1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            dsu[i] = i-1;
        } else {
            dsu[i] = findP(arr[i],i-1, dsu,arr);
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<dsu[i]+1<<" ";
}
    return 0;
}