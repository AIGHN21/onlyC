#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<cstring>
using namespace std;

//int main(){
//    IO
//    ll n;
//    cin>>n;
//    vector<ll>arr(n+1),dp(n+1),maxn(n+1);
//
//    for(ll i = 1;i<=n;i++){
//        cin>>arr[i];
//    }
//    dp[1]=arr[1];
//    maxn[1]=arr[1];
//    ll ans = 0;
//    for(ll i = 2 ; i<=n ;i++){
//        dp[i]=max(dp[i-1]+arr[i],arr[i]);
//        if(dp[i]==arr[i]){
//            maxn[i]=dp[i];
//        }
//        else{
//            maxn[i]=max(maxn[i-1],arr[i]);
//        }
//        ans = max(dp[i]-maxn[i],ans);
//    }
//    cout<<ans;
//    return 0;
//}
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    vector<string> rs = split(s," ");
     for(ll i = 1;i<=n;i++){
     cin>>arr[i];
   }
}
