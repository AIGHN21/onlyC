#include<iostream>
using namespace std;
typedef long long ll;
void Solve( ll dp1[] , ll dp2[]){
   ll l,r;
   cin>>l>>r;
   if(l>0){
    cout<<dp1[r]-(dp2[r]-dp2[l-1])*(l)-dp1[l-1];
   }
   else{
    cout<<dp1[r];
   }
   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   a
    string s ;
    cin>>s;
    int t;
    cin>>t;
    ll dp[s.length()]  , countChan[s.length()]{0};
    int n = s.length();
   int tmp = ( s[0] - '0');
   if(tmp%2==0){
      dp[0]=1;
       countChan[0]=1;
   }
   else{
      dp[0]=0;
      countChan[0]=0;
   }
   ll temp = 0;
   for(long i = 1 ; i < n ; i++){
      temp = (s[i] - '0');
      if(temp%2==0){
         countChan[i]=countChan[i-1]+1;
         dp[i]=dp[i-1]+1+i;
      }
      else{
         dp[i]=dp[i-1];
         countChan[i]=countChan[i-1];
      }
   } 
    for(int i = 0 ; i < t ; i++){
      Solve(dp,countChan);
    }
    return 0;
    }