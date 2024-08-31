#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i = 0 ;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0 ;i<n;i++){
        cin>>b[i];
    }
   
    int maxB = b[0];
    int maxV = a[0] + (k  - 1) * maxB;
    int tong =  a[0];
    int tong2;
    int end = ((k>n)?n:k);
   for(int i = 1 ; i < end ; i++ ){
        maxB = max(b[i], maxB);
        tong += a[i];
        tong2 =tong + (k - i - 1) * maxB;
        maxV = max(tong2, maxV);
    }
    cout<<maxV<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}