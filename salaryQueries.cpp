#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"q
long const maxn = 2*10e5;
using namespace std;
ll T[maxn*4],arr[maxn],n,q;
ll get(ll id , ll l , ll r , ll a, ll b){
    if(l==r){
        return (arr[l]>= a && arr[l]<=b)?1:0;
    }
    ll mid = (l+r)/2;
    return get(id*2,l,mid,a,b)+get(id*2+1,mid+1,r,a,b);
}
int main(){
    IO
    cin>>n>>q;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    string s;
    while(q--){
        cin>>s;
        if(s=="?"){
            ll a,b;
            cin>>a>>b;
            cout<<get(1,1,n,a,b)<<"\n";
        }
        else{
            ll k,x;
            cin>>k>>x;
            arr[k]=x;
        }
    }
    return 0;
}
