#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
const ll maxn =  2*1e5;
struct bruh{
    ll prefix;
    ll suffix;
    ll sum;
    ll submax;
    ll value;
};
bruh T[maxn*4];ll arr[maxn];ll n,q;
void build(ll id,ll l , ll r){
    if(l==r){
        T[id].prefix=arr[l];
        T[id].suffix=arr[l];
        T[id].sum=arr[l];
        T[id].submax=arr[l];
        return ;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id].prefix = max(T[id * 2].prefix, T[id * 2].sum + T[id * 2 + 1].prefix);
    T[id].sum = T[id * 2].sum + T[id * 2 + 1].sum;
    T[id].suffix = max(T[id * 2 + 1].suffix, T[id * 2 + 1].sum + T[id * 2].suffix);
    T[id].submax = max({T[id * 2].submax, T[id * 2 + 1].submax, T[id * 2].suffix + T[id * 2 + 1].prefix});
//    T[id].value = max({T[id].prefix, T[id].sum, T[id].suffix, T[id].submax});
}
void update(ll id,ll l , ll r,ll pos,ll value){
//    if(pos>r || pos < l){
//        return ;
//    }
    if(l==r){
        T[id].prefix=value;
        T[id].suffix=value;
        T[id].sum=value;
        T[id].submax=value;
        return ;
    }
    ll mid = (l+r)/2;
    if(pos <= mid) update(id*2,l,mid,pos,value);
    else update(id*2+1,mid+1,r,pos,value);
    T[id].prefix = max(T[id * 2].prefix, T[id * 2].sum + T[id * 2 + 1].prefix);
    T[id].sum = T[id * 2].sum + T[id * 2 + 1].sum;
    T[id].suffix = max(T[id * 2 + 1].suffix, T[id * 2 + 1].sum + T[id * 2].suffix);
    T[id].submax = max({T[id * 2].submax, T[id * 2 + 1].submax, T[id * 2].suffix + T[id * 2 + 1].prefix});
//    T[id].value = max({T[id].prefix, T[id].sum, T[id].suffix, T[id].submax});
}
int main(){
    IO
    cin>>n>>q;
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(q--){
        int k,m; cin >> k >> m;
        update(1,1,n,k,m);
        if(T[1].submax>=0){
            cout<<T[1].submax<<"\n";
        }
        else{
           cout<<0<<"\n";
        }

    }
    return 0;
}
