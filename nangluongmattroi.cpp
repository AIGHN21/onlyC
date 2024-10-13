#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<climits>
using namespace std;
int const maxn = 10e6;
struct bruh{
    int fi,se;
    // fi=sum
    //se =min index}
};
long long arr[maxn],m,n,q,d;
bruh T[maxn*4];

void build(int id ,int l , int r){
    if(l==r){
        T[id].fi=arr[l];
        T[id].se=l;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    T[id].fi=T[id*2].fi+T[id*2+1].fi;
    if(arr[T[id*2].se]>arr[T[id*2+1].se])
    {
        T[id].se=T[id*2+1].se;
    }
    else if(arr[T[id*2].se]==arr[T[id*2+1].se]){
        T[id].se=min(T[id*2].se,T[id*2+1].se);
    }
    else T[id].se=T[id*2].se;
}
void update(int id ,int l , int r , int pos , int val){
    if(l==r){
        T[id].fi=val;
        return;
    }
    int mid = (l+r)/2;
    if(pos<=mid){
        update(id*2,l,mid,pos,val);
    }
    else{
        update(id*2+1,mid+1,r,pos,val);
    }
    T[id].fi=T[id*2].fi+T[id*2+1].fi;
    if(arr[T[id*2].se]>arr[T[id*2+1].se]) T[id].se=T[id*2+1].se;
    else if(arr[T[id*2].se]==arr[T[id*2+1].se]) T[id].se=min(T[id*2].se,T[id*2+1].se);
    else T[id].se=T[id*2].se;
}

bruh getMin(int id , int l ,int r,int u,int v){
    if(l>v || r <u){
            bruh tmp;
    tmp.fi=0;
    tmp.se=0;
        return tmp;
    }
    if(l>=u && r<=v){
        return T[id];
    }
    int mid = (l+r)/2;
    bruh lefts=getMin(id*2,l,mid,u,v);
    bruh rights=getMin(id*2+1,mid+1,r,u,v);
    bruh middle ;
    middle.fi= lefts.fi+rights.fi;
    if(arr[lefts.se]<arr[rights.se]){
        middle.se=lefts.se;
    }
    else if(arr[lefts.se]==arr[rights.se]){
        middle.se=min(lefts.se,rights.se);
    }
    else{
        middle.se=rights.se;
    }
    return middle;
}
int main(){
    IO

    arr[0]=LLONG_MAX;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    build(1,1,n);
    while(m--){
        int a;
        cin>>a;
        if(a==1){
            int x;
            cin>>x;
            d=(d+x)%n;
        }
        else if(a==2){
            int s,t,p;
            cin>>s>>t>>p;
            bruh tmp = getMin(1,1,n,(s+(n-d))%n,(t+(n-d))%n);
            update(1,1,n,tmp.se,p);
        }
        else if(a==3){
            int k,l;
            cin>>k>>l;
             cout<<getMin(1,1,n,(k+(n-d))%n,(l+(n-d))%n).fi<<"\n";
        }
    }

    return 0;
}
