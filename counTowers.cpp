#include <iostream>
using namespace std;
const int maxn = 1e9+7;
int main()
{

  int n,t;
  cin>>t;
  while(t--){
     cin>>n;
        long long dp[n],dpx[n],dpy[n];
        dp[0]=2;
        dpx[0]=1;
        dpy[0]=1;
        for(int i = 1 ; i < n ; i++){
      dpx[i]=(2*dpx[i-1]+dpy[i-1])%1000000007;
      dpy[i]=(4*dpy[i-1]+dpx[i-1])%1000000007;
      dp[i]=dpx[i]+dpy[i];
        }
        cout<<dp[n-1]%1000000007<<"\n";
  }
}
