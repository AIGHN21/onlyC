#include<iostream>
#include<climits>
using namespace std;
const int maxn = 10e5+1;
#define ll long long
ll T[maxn*4];
ll arr[maxn];
ll n;
void build(ll id , ll l , ll r){
    if(l==r){
        T[id]=arr[l];
        return ;
    }
    ll mid = (r+l)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id] = min(T[id*2],T[id*2+1]);
}
void update(ll id , ll l , ll r, ll pos ){
    if(pos<l || pos>r){
        return ;
    }
    if(l==r){
        T[id]=INT_MAX;
        return ;
    }

    ll mid = (r+l)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    T[id] = min(T[id*2],T[id*2+1]);

}
ll getValue(ll id ,ll l , ll r){
        if(l==r){
            return l;
        }
        ll mid = (l+r)/2;
        ll left = T[id*2];
        ll right = T[id*2+1];
        if(left<=right){
            return getValue(id*2,l,mid);
        }
        else{
            return getValue(id*2+1,mid+1,r);
        }
}
int main(){
    cin>>n;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    ll ans=0;
    while(T[1]!=INT_MAX){
    ans=ans+1;
    ll pos = getValue(1,1,n);
    update(1,1,n,pos);
    if(pos==1){
             update(1,1,n,pos+1);
    }
      else if(pos==n){
             update(1,1,n,pos-1);
    }
      else{
            update(1,1,n,pos-1);
            update(1,1,n,pos+1);
      }
   }
    cout<<ans;

}
