#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 2e5+7;
ll T[maxn*4],lazy[maxn*4],arr[maxn],n,q;
void build(ll id , ll l , ll r){
    if(l==r){
        T[id]=arr[l];
        return ;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id] = T[id*2]+T[id*2+1];
}
void fix(ll id , ll l , ll r){
    if(!lazy[id]){
        return ;
    }
    T[id]+=lazy[id];
    if(l!=r){
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
    }
    lazy[id]=0;
}
void update(ll id , ll l , ll r, ll u , ll v, ll val){
    fix(id,l,r);
    if(l>v || r<u){
        return ;
    }
    if(l >= u && r <= v){
        lazy[id]=(r-l+1)*val;
        fix(id,l,r);
        return;
    }
    ll mid = (l+r)>>1;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    T[id]=T[id*2]+T[id*2+1];
}
ll get(ll id , ll l , ll r ,ll pos){
    fix(id,l,r);
    if(l==r){
        return T[id];
    }
    ll mid = (l+r)>>1;
    if(pos<=mid){
        return get(id*2,l,mid,pos);
    }
    else {
        return get(id*2+1,mid+1,r,pos);
    }
}
int main(){
    IO
    cin>>n>>q;
    for(ll i = 1 ; i<= n ;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--){
        ll k;
        cin>>k;
        if(k==1){
                ll a, b,val;
        cin>>a>>b>>val;
            update(1,1,n,a,b,val);
        }
        else{
                ll pos;
        cin>>pos;
            cout<<get(1,1,n,pos)<<"\n";
        }
    }

    return 0;
}

