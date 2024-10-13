    #include <iostream>
    #include <vector>
    #include <algorithm>
    #define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #define ll long long
    #define ln "\n"
    const ll maxn = 2*1e5+7;
    ll m,n;
    ll T[maxn*4],arr[maxn],arr2[maxn];
    using namespace std;
    void build(ll id, ll l, ll r){
        if(l==r){
            T[id]=arr[l];
            return;
        }
        ll mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        T[id]=max(T[id*2],T[id*2+1]);
    }
     void update(ll id , ll l , ll r, ll pos,ll val){
        if(l==r){
            T[id]=val;
            return;
        }
        ll mid = (l+r)/2;
        if(pos<=mid){
            update(1,l,mid,pos,val);
        }
        else{
            update(1,mid+1,r,pos,val);
        }
        T[id]=max(T[id*2],T[id*2+1]);
    }
    ll getV(ll id , ll l , ll r ,ll room){
        if(T[id]<room){
            return 0;
        }
        if(l==r){
            update(1,1,n,l,T[id]-room);
            return l;
        }
        ll mid = (l+r)/2;
        if(T[id*2]>=room){
            return getV(id*2,l,mid,room);
        }
        else{
            return getV(id*2+1,mid+1,r,room);
        }
    }
    int main(){
        IO
        cin>>n>>m;
        for(ll i = 1 ; i <= n ; i++){
            cin>>arr[i];
        }
        for(ll i = 1 ; i <= m ; i++){
            cin>>arr2[i];
        }
        build(1,1,n);
        for(int i = 1 ; i <= m ; i++){
            cout<<getV(1,1,n,arr2[i])<<" ";
        }
        return 0;
    }

