#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
const ll maxn= 2e5;
using namespace std;
ll T[maxn*4],arr[maxn],arr2[maxn],n;
void build(ll id , ll l , ll r){
  if(l==r){
        T[id]=1;
        return ;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id]=T[id*2]+T[id*2+1];
}
void update(ll id , ll l , ll r,ll pos){
        if(l==r){
        T[id]=0;
        return ;
        }
        ll mid = (l+r)/2;
        if(pos<=mid){
            update(id*2,l,mid,pos);
        }
        else{
            update(id*2+1,mid+1,r,pos);
        }
        T[id]=T[id*2]+T[id*2+1];
}
ll get(ll id , ll l , ll r,ll val){
    if(l==r){
        return l;
    }
    ll mid = (l+r)/2;
    if(val<=T[id*2]){
        return get(id*2,l,mid,val);
    }
    else{
        return get(id*2+1,mid+1,r,val-T[id*2]);
    }
}
int main(){
    IO
    cin>>n;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr2[i];
    }
    ll k ;
    for(ll i = 1 ; i <= n ; i++){
        k = get(1,1,n,arr2[i]);
        cout<<arr[k]<<" ";
        update(1,1,n,k);
    }
    return 0;
}
