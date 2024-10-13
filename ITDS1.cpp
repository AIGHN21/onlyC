#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<set>
ll const maxn = 1e5+7;
using namespace std;
struct bruh{
    ll value;
    set<ll> mutiset;
};
bruh T[maxn*4];
ll arr[maxn],n,q;

void build(ll id , ll l , ll r){
    if(l==r){
       T[id].value = -1;
       T[id].mutiset.insert(arr[l]);
       return ;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id*2].mutiset.insert(T[id*2+1].mutiset.begin(),T[id*2+1].mutiset.end());
    T[id].mutiset = T[id*2].mutiset;
}

void update(ll id , ll l , ll r,ll pos , ll val){
    if(l==r){
        T[id].mutiset.erase(T[id].mutiset.find(arr[l]));
        T[id].mutiset.insert(val);
        arr[l] = val;
        return ;
    }
    ll mid = (l+r)>>1;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id*2].mutiset.insert(T[id*2+1].mutiset.begin(),T[id*2+1].mutiset.end());
    T[id].mutiset = T[id*2].mutiset;

}

bruh get(ll id , ll l , ll r ,ll u , ll v, ll k ){
    if(l>v || r<u){
        return {-1,{0}};
    }
    if(l>=u && r<=v){
        auto it = T[id].mutiset.lower_bound(k);
        if (it != T[id].mutiset.end()) {
            return {*it, T[id].mutiset};
        } else {
            return {-1,{}};
        }
    }
    ll mid = (l+r)>>1;
    bruh left = get(id*2,l,mid,u,v,k);
    bruh right = get(id*2+1,mid+1,r,u,v,k);
    return (left.value > right.value) ? left : right;
}

int main(){
    IO
    cin>>n>>q;
    for(ll i =1 ; i<= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    ll x;
    while(q--){
        cin>>x;
        if(x==1){
            ll i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
        }
        else{
            ll l,r,k;
            cin>>l>>r>>k;
            ll index = get(1,1,n,l,r,k).value;
            cout<<index<<ln;
        }
    }
    return 0;
}
