#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    long long n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0 ; i < n ; i++){ 
       cin>>arr[i];
    }
    vector<ll> dp(n+1);
    dp[0]=0;
    dp[1]=0;
    for(int i = 2 ; i < n + 1 ; i++){
        dp[i] = min(dp[i-1]+arr[i-1],dp[i-2]+arr[i-2]);
    }
    cout<<dp[n];
   }