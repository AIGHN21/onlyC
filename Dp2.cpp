#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    long long n,k;
    cin >> n>>k;
    vector<ll> arr(n),dp(n,1),findMax(n);
    for(int i = 0 ; i < n ; i++){ 
       cin>>arr[i];
    }
    ll maxN = 0;
    dp[0] = arr[0];
    findMax[0] = arr[0];
    for(int i = 1 ; i < k ; i++){
        dp[i] = arr[i];
        findMax[i] = max(arr[i],findMax[i-1]);

    }
    for(int i = k ; i < n ; i++){
        
        dp[i]=arr[i]+findMax[i-k];
        maxN = max(dp[i],maxN);   
        findMax[i] = max(dp[i],findMax[i-1]);     
    }
     cout<<maxN;
   }