#include<iostream>
using namespace std;
const long maxn=10e5+9;
#define ll long long
#include<math.h>
#include<vector>;
#include<climits>
pair<ll,ll> T[maxn*4];ll arr[maxn];
ll n,m;
pair<ll,ll> get(ll id , ll l , ll r ,ll u , ll v){
    if(l>v || r < u){
        return {INT_MIN,INT_MAX};
    }
    if(l>=u && r<=v){
        return T[id];
    }
    ll mid = (l + r)/2;
    pair<ll,ll> temp;
    pair<ll,ll> left = get(id*2,l,mid,u,v);
    pair<ll,ll> right = get(id*2+1,mid+1,r,u,v);
    temp.first = max(left.first,right.first);
    temp.second = min(left.second,right.second);
    return temp;
}
void build(ll id ,ll l , ll r){
    if(l==r){
        T[id].first=arr[l];
        T[id].second=arr[l];
        return;
    }
    ll mid = ( l + r )/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id].first=max(T[id*2].first,T[id*2+1].first);
    T[id].second=min(T[id*2].second,T[id*2+1].second);
}
/*
void fix(ll id ,ll l , ll r){
    if(!lazy[id]){
        return ;
    }
    T[id]=T2[id]-T[id];
    if(l!=r){
        ll mid = ( l + r )/2;
        lazy[2*id]+=1;
        lazy[2*id+1]+=1;
    }
    lazy[id] = 0;
}
void update(ll id , ll l , ll r , ll st , ll ed){
    fix(id,l,r);
    if(l>ed || r < st){
        return ;
    }
    if(l>=st && r <= ed){
        lazy[id]=1;
        fix(id,l,r);
        return;
    }
    ll mid = ( l + r )/2;
   update(id*2,l,mid,st,ed);
   update(id*2+1,mid+1,r,st,ed);
   T[id]=T[id*2]+T[id*2+1];
}*/
int main(){
    cin>>n>>m;
    for(int i = 1 ; i <=n ; i++){
       cin>>arr[i];
    }
    build(1,1,n);
    while(m--){
        int a,b ;
        cin>>a>>b;

        pair<ll,ll> tmp = get(1,1,n,a,b);
        cout<<abs(tmp.first-tmp.second)<<"\n";
        }
}
