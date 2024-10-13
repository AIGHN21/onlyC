#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n
#include<unordered_map>
const ll maxn = 2e5+7;
ll T[maxn*4],n,arr1[maxn],arr2[maxn];
ll ts[maxn];
using namespace std;
void update(ll id , ll l , ll r,ll pos,ll val){
    if(l==r){
       T[id]=max(T[id],val);
       return;
    }
    ll mid = (l+r)/2;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id]=max(T[id*2],T[id*2+1]);
}
ll get(ll id , ll l , ll r , ll u){
    if(u<l){
        return 0;
    }
    if(r<=u){
        return T[id];
    }
    ll mid = (l+r)/2;
    return max(get(id*2,l,mid,u),get(id*2+1,mid+1,r,u));
}
int main(){
    IO
    cin>>n;
    ll dp[n+1];
    ll clone[n+1];
    for(ll i = 1; i <= n ; i++){
        cin>>arr1[i];
        clone[i] = arr1[i];
    }
    for(ll i = 1; i <= n ; i++){
        cin>>arr2[i];
    }
    sort(clone+1,clone+n+1);
    ll mn = 1;
    unordered_map<ll,ll> m;
    for(ll i = 1 ; i <= n ; i++){
        if(m.find(clone[i])==m.end()){
            m[clone[i]]=mn++;
        }
    }
    for(ll i = 1 ; i <= n ; i++){
        arr1[i] = m[arr1[i]];
    }
    ll ans = arr2[1];
    update(1,1,n,arr1[1],arr2[1]);
    dp[1] = arr2[1];
    for(ll i = 2 ; i <= n ; i++){
        ll val = get(1,1,n,arr1[i]-1)+arr2[i];
        update(1,1,n,arr1[i],val);
        dp[i]=val;
        ans = max(dp[i],ans);
    }
    cout<<ans;
    return 0;
}
