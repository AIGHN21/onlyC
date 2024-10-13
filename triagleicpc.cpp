#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"

using namespace std;

int main(){
    IO
    ll n;
    cin>>n;
    ll arr[n+1];
    ll dp1[n+1]={0},dp2[n+1]={0};
    for(ll i = 1 ; i<=n;i++){
        cin>>arr[i];
    }
    dp1[1]=1;
    dp2[n]=1;
    for(ll i = 2 ; i<=n;i++){
        if(arr[i]>dp1[i-1]){
            dp1[i]=dp1[i-1]+1;
        }
        else{
            dp1[i]=arr[i];
        }
    }
    for(ll i = n-1 ; i>=0;i--){
        if(arr[i]>dp2[i+1]){
            dp2[i]=dp2[i+1]+1;
        }
        else{
            dp2[i]=arr[i];
        }
    }
//    for(ll i = 1 ; i<=n;i++){
//        cout<<dp1[i]<<" ";
//    }
//    cout<<ln;
//    for(ll i = 1 ; i<=n;i++){
//        cout<<dp2[i]<<" ";
//    }
   ll ans = 1;
    for (ll i = 2; i <= n-1; i++) {
            if(dp1[i-1] >= arr[i]-1 && dp2[i+1]>=arr[i]-1){
                ans = max(arr[i],ans);
            }
            else{
                 ans = max(min(dp1[i-1],dp2[i+1])+1,ans);
            }

    }
    cout<<ans;


}
