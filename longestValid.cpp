#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
        vector<int> dp(n);
        vector<int> check(n,0);
        int count = 0;
    for(int i = 1 ; i < s.length() ; i++){
          if(s[i]=='('){
            check[i]=1;
            count++;
            dp[i]=dp[i-1];
          }
          else{
            
          }
        }
        for(int i = 0 ; i < dp.size() ;i++){
            cout<<dp[i]<<" ";
        }
        return 0;
}