#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#define maxn 17000
using namespace std;
ll T[maxn*4] , arr[maxn];
ll n;
void build(ll id , ll l , ll r){
    if(l==r){
        T[id]=arr[l];
        return ;
    }
    ll mid = (l + r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id]=min(T[id*2],T[id*2+1]);
}
ll get(ll id,ll l , ll r ,ll u , ll v){
    if(l>v || r < u){
        return INT_MAX;
    }
    if(l>=u && r<=v){
        return T[id];
    }
    ll mid = (l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
    IO

    ll t;
    cin>>t;
    while(t--){
    ll k;
    cin>>n>>k;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    for(ll i = k ; i <= n ; i++)
        cout<<get(1,1,n,i-k+1,i)<<"\n";
    }
    return 0;
}
