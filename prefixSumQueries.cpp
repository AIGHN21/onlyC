#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const ll maxn= 2e5;
using namespace std;
ll arr[maxn],n,q;
struct bruh{
    ll prefix;
    ll sum;
};
bruh T[maxn*4];
void build(ll id , ll l , ll r){
    if(l==r){
        T[id].prefix=arr[l];
        T[id].sum=arr[l];
        return ;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id].sum=T[id*2].sum+T[id*2+1].sum;
    T[id].prefix=max({T[id].sum,T[id*2].sum+T[id*2+1].prefix,T[id*2].prefix,T[id*2].sum});
}
void update(ll id , ll l , ll r , ll pos , ll val){
    if(l==r){
        T[id].prefix=val;
        T[id].sum=val;
        return ;
    }
    ll mid = (l+r)/2;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id].sum=T[id*2].sum+T[id*2+1].sum;
    T[id].prefix=max({T[id].sum,T[id*2].sum+T[id*2+1].prefix,T[id*2].prefix,T[id*2].sum});
}
ll get(ll id , ll l , ll r ,ll u , ll v){
    if(l>v || r < u){
        return 0;
    }
    if(l>= u && r<=v){
        return T[id].prefix;
    }

}
int main(){
    IO
    int t; cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
