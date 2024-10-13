#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<map>
const ll maxn = 30000;
using namespace std;
ll T[maxn*4];
void update(ll id , ll l , ll r , ll pos , ll val){
    if(l==r){
        T[id]=val;
        return;
    }
    ll mid = (l+r)/2;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id]=max(T[id*2+1],T[id*2]);
}
ll getV(ll id , ll l , ll r , ll value){
    if(l>value || r < 1 ){
        return 0;
    }
    if(r<=value && l>=1){
        return T[id];
    }
    ll mid = (l+r)/2;
    return max(getV(id*2,l,mid,value),getV(id*2+1,mid+1,r,value));
}

int main(){
    ll n ;
    map<ll,ll> maps;
    cin>>n;

    vector<ll> arr1(n),arr2(n),arr3(n);
    for(int i = 0 ; i < n ;i++){
        cin>>arr1[i];
    }
    if(n==1){
        cout<<1;
    }
    else{


    arr3 = arr1;
    sort(arr1.begin(),arr1.end());
    int dem = 1;
    arr2[0]=1;
    maps[arr1[0]]=1;
    ll ans = 0 ;
    for(ll i = 1 ; i < n ; i++){
        if(arr1[i]==arr1[i-1]){
            arr2[i]=dem;
        }
        else{
            arr2[i]=++dem;
        }
         maps[arr1[i]]=arr2[i];
    }

    for(ll i = 0 ; i < n ; i++){
        arr3[i]=maps[arr3[i]];
    }

    vector<ll> dp(n,1);
    update(1,1,n,arr3[0],1);
    for(ll i = 1 ; i < n ; i++){
        dp[i]=getV(1,1,n,arr3[i]-1)+1;
        update(1,1,n,arr3[i],dp[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    }
    return 0;
}
