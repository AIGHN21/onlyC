#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn = 2e5+7;
ll T[maxn*4],arr[maxn],n,q;
ll get(ll id , ll l , ll r , ll u ,ll v,ll val){
    if(l>v || r <u ){
        return 0;
    }
    if(l==r){
        return (arr[l]==val)?l*l:0;
    }
}
int main(){
    IO
    cin>>n>>q;
    for(ll i = 1 ; i < n ; i++){
        cin>>arr[i];
    }

    return 0;
}
