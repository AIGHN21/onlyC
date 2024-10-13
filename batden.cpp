#include<iostream>
using namespace std;
const long maxn=10e5+9;
#define ll long long
ll T[maxn*4],T2[maxn*4],lazy[maxn*4];
ll n,m;
ll get(ll id , ll l , ll r ,ll u , ll v){
    if(l>v || r < u){
        return 0;
    }
    if(l==r){
        return T[id];
    }
    ll mid = (l + r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void build(ll id ,ll l , ll r){
    if(l==r){
        T2[id]=1;
        return;
    }
    ll mid = ( l + r )/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T2[id]=T2[id*2]+T2[id*2+1];
}
void fix(ll id ,ll l , ll r){
    if(!lazy[id]){
        return ;
    }
    T[id]=T2[id]-T[id];
    if(l!=r){
        ll mid = ( l + r )/2;
        lazy[2*id]+=lazy[id];
        lazy[2*id+1]+=lazy[id];
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
}
int main(){
    cin>>n>>m;
    build(1,1,n);
    //for(int i = 1 ; i < 2*n ; i++){
     //   cout<<T2[i]<<" ";
    //}
    //cout<<"\n";
    while(m--){
        int k,a,b ;
        cin>>k>>a>>b;
        if(k==0){
            update(1,1,n,a,b);
            //cout<<"\n";
           // for(int i = 1 ; i < 2*n ; i++){
          //      cout<<T[i]<<" ";
           // }
          //  cout<<"\n";
        }
        else{
            cout<<get(1,1,n,a,b)<<"\n";
        }
    }
}
