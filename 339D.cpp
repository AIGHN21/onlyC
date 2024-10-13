#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<cmath>
#define maxn 131072
int T[maxn*4], arr[maxn];
int n,ors;
using namespace std;
void build(int id, int l, int r, int depth) {
    if(l == r) {
        T[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid, depth+1);
    build(id*2+1, mid+1, r, depth+1);

    if (depth % 2 == 0) {
        if (ors == 1)
            T[id] = T[id*2] | T[id*2+1];
        else
            T[id] = T[id*2] ^ T[id*2+1];
    } else {
        if (ors == 1)
            T[id] = T[id*2] ^ T[id*2+1];
        else
            T[id] = T[id*2] | T[id*2+1];
    }
}
void update(int id , int l , int r ,int depth, int pos , int val){
    if(pos>r || pos <l){
        return;
    }
    if(l==r){
        T[id]=val;
        return ;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, depth+1,pos,val);
    update(id*2+1, mid+1, r, depth+1,pos,val);
    if (depth % 2 == 0) {
        if (ors == 1)
            T[id] = T[id*2] | T[id*2+1];
        else
            T[id] = T[id*2] ^ T[id*2+1];
    } else {
        if (ors == 1)
            T[id] = T[id*2] ^ T[id*2+1];
        else
            T[id] = T[id*2] | T[id*2+1];
    }

}
int main() {
    IO
    int q;
    cin >>n>>q;
    if (n % 2 != 0){
        ors = 1;
    } else {
        ors = 0;
    }

    int size = (1 << n);
    for (int i = 1; i <= size; i++) {
        cin >> arr[i];
    }
    build(1, 1, size, 0);
    while(q--){
        int a;
        long long b;
        cin>>a>>b;
        update(1,1,size,0,a,b);
        cout<<T[1]<<ln;
    }
    return 0;
}
