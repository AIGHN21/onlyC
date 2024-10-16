#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 101;
struct point{
    ll x,y,z,w;
};
point T[maxn*4]
void build(ll id , ll l , ll r){
    if(l==r){
        T[id].w=0;
        return ;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id] = T[id*2]+T[id*2+1];
}

void update(ll id , ll l , ll r, pos, ll val){

    if(l>v || r<u){
        return ;
    }
    if(l==r){
        T[id]+=val;
        return;
    }
     ll mid = (l+r)>>1;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
         update(id*2+1,mid+1,l,pos,val);
    }
    T[id].x=T[id*2].x+T[id*2+1];
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

