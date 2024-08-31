#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> arr(3,vector<long long>(n));
    for(int i = 0 ; i < 3 ; i++){ 
        for(int j = 0 ; j < n ; j++ ){
            cin>>arr[i][j];
        }
    }
   vector<vector<long long>> dp(3,vector<long long>(n));
        dp[0][0] =arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = arr[2][0];
   for(int i = 1 ; i < n ; i++){
        dp[0][i] = max(dp[1][i-1],dp[2][i-1])+arr[0][i];
        dp[1][i] = max(dp[0][i-1],dp[2][i-1])+arr[1][i];
        dp[2][i] = max(dp[0][i-1],dp[1][i-1])+arr[2][i];
   }
   long long maxV = 0;
   for(int i = 0 ; i < 3 ; i++){
    maxV = max(dp[i][n-1],maxV);
   }
   cout<<maxV;

   
}