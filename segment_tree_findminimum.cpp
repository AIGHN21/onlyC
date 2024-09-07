#include<iostream>
using namespace std;
#define ll long long
ll T[100000000];
void build(ll arr[],ll id , ll l , ll r){
    if(l==r){
        T[id] = arr[l];
        return ;
    }
    ll mid = (r+l)/2;
    build(arr,id*2,l,mid);
    build(arr,id*2+1,mid+1,r);
    T[id] = min(T[id*2],T[id*2+1]);
}
ll getMin(ll arr[],ll id , ll l ,ll r,ll u ,ll v){
    if(l>=u && r <=v){
        return T[id];
    }
    if(l==r && l >=u && l<=v){
        return T[id];
    }
    if(l>v || r < u){
        return INT32_MAX;
    }
    ll mid = (r+l)/2;
    ll tong =min(getMin(arr,id*2,l,mid,u,v),getMin(arr,id*2+1,mid+1,r,u,v));
    return tong;
}
int main(){
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    build(arr,1,0,n-1);
    while(t--){
        ll l,r;
        cin>>l>>r;
        cout<<getMin(arr,1,0,n-1,l-1,r-1)<<"\n";
    }
}
