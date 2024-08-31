#include <bits/stdc++.h>
using namespace std;
void Solve(){
     int n;
     cin>>n;
     int k ;
     int value = 2;
     double maxV = INT_MIN;
     for(int i = 2 ; i <= n ; i++){ 
        k = n/i;
        if((k*k*i+k*i)*1.0/2>maxV && k*i<=n){
            maxV = (k*k*i+k*i)*1.0/2;
            value = i;
        }
     }
     cout<<value<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}