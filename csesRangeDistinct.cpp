#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 2*10e5+1;
ll T[maxn*4],arr[maxn];
#include<unordered_map>
unordered_map<ll,ll> maps;
void build(ll id,ll l ,ll r){
    if(l==r){
        maps[arr[l]]=(maps[arr[l]]==0)?1:0;
        T[id]=0;
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id]=0;
}
ll getV(ll id,ll l, ll r, ll u, ll v){
    if(u==v){
        return 1;
    }
    if(l>v || r < u){
        return 0;
    }
    if(l==r && r<=v && l>=u){
        maps[arr[l]]=(maps[arr[l]]==0)?1:0;
        return maps[arr[l]];
    }
    ll mid = (l+r)/2;
    return getV(id*2,l,mid,u,v)+getV(id*2+1,mid+1,r,u,v);

}
int main(){
    IO
    ll n,q;
    cin>>n>>q;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<getV(1,1,n,a,b)<<"\n";
        for (auto& pair : maps) {
        pair.second = 0;
        }
    }
    return 0;
}
