#include<iostream>
using namespace std;
#define ll long long
#define MAXN 100000000
ll st[MAXN],arr[MAXN];
ll n,q;
void build(ll id,ll l , ll r){
    if(l==r){
        st[id]=arr[l];
        return ;
    }
    ll mid = (l+r)/2;
    build(id*2  ,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
void update(ll id,ll l,ll r ,ll pos,ll val){
    if(l==r && l==pos){
        st[id]=val;
        arr[l]=val;
        return ;
    }
    if (r < pos || l > pos) {
        return;
    }
    ll mid = (l + r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
ll getMin(ll id,ll l ,ll r ,ll u ,ll v ){
    if(l>v || r<u){
        return 10000000;
    }
    if(l>=u && r<=v){
        return st[id];
    }
    ll mid = (r+l)/2;
    return min(getMin(id*2,l,mid,u,v),getMin(id*2+1,mid+1,r,u,v));
}
int main(){
    // cin>>n>>q;
    cin>>n;
    for(ll i = 1 ; i <= n ;i++){
        cin>>arr[i];
    }
   build(1,1,n);
    for(ll i = 1 ; i <=4*n; i++){
       cout<<st[i]<<" ";
    }

    // // cout<<getMin(1,1,n,2,4)<<"\n";
    // while(q--){
    //         ll t;
    //         cin>>t;
    //     if(t==1){
    //         ll pos,val;
    //         cin>>pos>>val;
    //         update(1,1,n,pos,val);
    //         }
    //     else{
    //         ll a,b;
    //         cin>>a>>b;
    //         cout<<getMin(1,1,n,a,b)<<"\n";
    //     }
    // }
    return 0;
}


