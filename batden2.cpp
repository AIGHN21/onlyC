#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const ll maxn = 1e5+7;
using namespace std;
struct bruh{
    ll close;
    ll open;
};
bruh T[maxn*4];
ll n,q,lazy[maxn*4];
void build(ll id , ll l , ll r){
    if(l==r){
        T[id].close = 1;
        T[id].open = 0;
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id].close = T[id*2].close+T[id*2+1].close;
    T[id].open = T[id*2].open+T[id*2+1].open;
}
void fix(ll id , ll l , ll r){
    if(!lazy[id]){
        return ;
    }
    ll temp = T[id].close;
    T[id].close = T[id].open;
    T[id].open = temp;
    if(l!=r){
        lazy[id*2] ^= lazy[id];
        lazy[id*2+1] ^= lazy[id];
    }
    lazy[id] = 0;
}
void update(ll id , ll l , ll r , ll u , ll v){
    fix(id,l,r);
    if(l>v || r<u){
        return ;
    }
    if(l>=u && r<=v){
        lazy[id] = 1;
        fix(id,l,r);
        return ;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    T[id].close = T[id*2].close+T[id*2+1].close;
    T[id].open = T[id*2].open+T[id*2+1].open;
}
ll get(ll id , ll l , ll r , ll u ,ll v){
    fix(id,l,r);
    if(l>v || r<u){
        return 0 ;
    }
    if(l>=u && r<=v){
        return T[id].open ;
    }
    ll mid = (l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);

}

int main(){
    IO
    cin>>n>>q;
    build(1,1,n);
     while(q--){
        int k,a,b ;
        cin>>k>>a>>b;
        if(k==0){
            update(1,1,n,a,b);
//            for(int i = 1 ; i <= 2*n ; i++){
//                cout<<T[i].open<<" ";
//            }
//            cout<<"\n";
//        }
        else{
            cout<<get(1,1,n,a,b)<<"\n";
        }
    }
    return 0;
}
