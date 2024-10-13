#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn =  2*10e5+1;
ll T[maxn*4],arr[maxn],lazy1[maxn*4],lazy2[maxn*4];
ll n,q;
void build(ll id,ll l,ll r){
    if(l==r){
        T[id]=arr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id]=T[id*2]+T[id*2+1];
}
void fix(ll id,ll l , ll r){
    if(lazy1[id]==0 && lazy2[id]==0){
        return ;
    }
    if(lazy2[id]!=0){
        lazy2[id]+=lazy1[id];
        lazy1[id]=0;
    }
    if(l!=r){
        if(lazy1[id]==0){
            lazy2[id*2]=lazy2[id];
            lazy2[id*2+1]=lazy2[id];
        }
        else{
            lazy1[id*2]+=lazy1[id];
            lazy1[id*2+1]+=lazy1[id];
        }
    }
    lazy[id]=0;
}
void update1(ll id , ll l , ll r ,ll u , ll v, ll val){
    fix(id,l,r);
    if(l>v || r <u){
        return ;
    }
    if(l >= u && r <=v){
        if(!lazy2[id]){
            lazy[id]+=val;
        }
        else{
            lazy2[id]+=val;
        }
        fix(id,l,r);
        return ;
    }
}
void update2(ll id ,ll l,ll r ,ll u , ll v , ll val){
     //fix(id,l,r);
     if(l>v || r < u){
        return ;
     }
     if()
}
int main(){
    IO
    int t; cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
