#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(string s){
   ll l,r;
   cin>>l>>r;
   vector<ll> dp(r-l+1);
   int n = dp.size();
   int tmp = ( s[l] - '0');
   if(tmp%2==0){
      dp[0]=1;
   }
   else{
      dp[0]=0;
   }
   
   ll dem = 1;
   ll temp = 0;
   for(long i = l+1 ; i <= r ; i++){
      dem++;
      temp = (s[i] - '0');
      if(temp%2==0){
         dp[i-l]=dp[i-l]+dp[i-l-1]+dem;
      }
      else{
         dp[i-l]=dp[i-l-1];
      }
   } 
   cout<<dp[n-1];
}
int main(){
    string s ;
    cin>>s;
    int t;
    cin>>t;
    for(int i = 0 ; i < t ; i++){
      Solve(s);
    }
    return 0;
    
    }