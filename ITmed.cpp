#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<climits>
using namespace std;
const ll maxn = 1e5+12;
ll T[maxn*4],arr[maxn],n,k;
const ll INF = -99999999;
void update(ll id, ll l, ll r, ll pos, ll value) {
    if (l == r) {
        T[id] = value;
        return;
    }
    ll mid = l + (r - l) / 2;
    if (pos <= mid) {
        update(id * 2, l, mid, pos, value);
    } else {
        update(id * 2 + 1, mid + 1, r, pos, value);
    }
    T[id] = max(T[id * 2], T[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll u, ll v) {
    if (v < l || u > r) {
        return INF;
    }
    if (l >= u && r <= v) {
        return T[id];
    }
    ll mid = l + (r - l) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    cin>>n>>k;
    ll dp[maxn];
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    dp[1]=max((ll)0,arr[1]);
    update(1,1,n,1,dp[1]);
    ll ans = dp[1];
    if(k>=2){
       for(ll i = 2 ; i<= k ; i++){
            ll a =max(arr[i],arr[i]+get(1,1,n,1,i-1));
            dp[i] = max(a,(ll)0);
//            cout<<i <<" : "<<dp[i]<<" ";
            update(1,1,n,i,dp[i]);
            ans = max(ans,dp[i]);
        }
    }
    for(ll i = k+1 ; i<=n ;i++){
//        cout<<"vong lap thu "<<i<<" gia tri be nhat truoc do dla "<<get(1,1,n,i-k,i-1 )<<ln;

        ll a = max(get(1,1,n,i-k,i-1)+arr[i],arr[i]);
        a = max(a,(ll)0);
        dp[i] = a;
        update(1,1,n,i,dp[i]);
        ans = max(ans,dp[i]);
    }
//    for(ll i = 1 ; i <=4 *  n ; i++){
//        cout<<T[i]<<" ";
//    }
//    cout<<ln;
//    for(ll i = 1 ; i <= n ; i++){
//         cout<<i <<" : "<<dp[i]<<" ";
//    }
//    cout<<ln;
    cout<<ans;


}
