#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include <climits>

using namespace std;
const ll maxn = 1e5+7;
ll T[maxn*4],arr[maxn],n,q;
void build(ll id , ll l , ll r ){
    if(l==r){
        T[id]=arr[l];
        return;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id] = max(T[id*2],T[id*2+1]);
}
void update(ll id, ll l , ll r, ll pos ,ll val){
    if(l==r){
        T[id]=val;
        return;
    }
    ll mid = (l+r)>>1;
    if(pos<=mid){
       update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id] = max(T[id*2],T[id*2+1]);
}
ll get(ll id , ll l , ll r , ll u , ll v ){
    if(l>v || r<u){
        return LLONG_MIN;
    }
    if(l>=u && r<=v){
        return T[id];
    }
    ll mid = (l+r)>>1;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
    IO
    cin>>n;
    for(ll i = 1 ; i <= n ;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    cin>>q;
    ll k;
    while(q--){
        cin>>k;
        if(k==1){
              ll x,y;
              cin>>x>>y;
              update(1,1,n,x,y);
        }
        else{
                ll a,b;
        cin>>a>>b;
            cout<<get(1,1,n,a,b)<<"\n";
        }
    }
    return 0;
}
