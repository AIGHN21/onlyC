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
    ll arr[n+1][4],dp[n+1][3];
    for(ll i = 1 ; i<=n;i++){
        for(ll j = 1 ; j<=3;j++){
            cin>>arr[i][j];
        }

    }
    for(ll i = 1 ; i<= 3; i++){
        dp[1][i]=arr[1][i];
    }
    for(ll i = 2 ; i<=n;i++){

        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+arr[i][1];
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+arr[i][2];
        dp[i][3]=max(dp[i-1][1],dp[i-1][2])+arr[i][3];
    }
    ll ans = dp[n][1];
    for(ll i = 2 ; i<= 3 ;i++){
        ans = max(ans,dp[n][i]);
    }
    cout<<ans;


}
