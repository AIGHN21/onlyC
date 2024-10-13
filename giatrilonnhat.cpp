#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
int const maxn = 50000;
int T[maxn*4],lazy[maxn*4],arr[maxn],m,n,q;
void build(int id,int l, int r){

}
void fix(int id,int l , int r){
    if(!lazy[id]){
        return ;
    }
    T[id]+=lazy[id];
    if(l!=r){
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
    }
    lazy[id]=0;
}
void update(int id,int l , int r ,int u , int v , int val){
    if(l>v || r <u){
        return ;
    }
    fix(id,l,r);
    if(l>=u && r<=v){
        lazy[id]+=val;
        fix(id,l,r);
        return ;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    T[id]=max(T[id*2],T[id*2+1]);
}
int getV(int id , int l ,int r,int u,int v){
    if(l>v || r <u){
        return 0;
    }
    fix(id,1,n);
    if(l==r){
        return T[id];
    }
    int mid = (l+r)/2;
    return max(getV(id*2,l,mid,u,v),getV(id*2+1,mid+1,r,u,v));
}
int main(){
    IO
    cin>>n>>m;
    int u,v,k;
    while(m--){
        cin>>u>>v>>k;
        update(1,1,n,u,v,k);
    }
    cin>>q;
    int a,b;
    while(q--){
    cin>>a>>b;
    cout<<getV(1,1,n,a,b)<<"\n";
    }
    return 0;
}
