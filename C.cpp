#include<iostream>
using namespace std;
#include<string.h>
#include<map>
#include<vector>
typedef long long ll;
// int main()
// {
//     ll n;
//     cin>>n;
//     ll arr[n-1]={0};
//     ll ts[n+1]={0};
//     for(ll i = 0 ; i < n-1;i++){
//         cin>>arr[i];
//         ts[arr[i]]++;
//     }
//     for(ll i = 1 ; i <= n ; i++){
//         if(ts[i]==0){
//             cout<<i;
//             break;
//         }
//     }
//     return 0;
// }
// int main(){
//         ios_base::sync_with_stdio(false);
//     cin.tie(0);   
//     string s;
//     cin>>s;
//     vector<int> dp(s.size(),1);
    
//     for(int i = 1 ; i < s.size();i++){
//         if(s[i]==s[i-1]){
//             dp[i]=dp[i-1]+1;
//         }
//         else{
//             dp[i]=1;
//         }
//     }
//     int rs = 0;
//     for(int i = 0 ; i < dp.size(); i++){
//        rs = max(rs,dp[i]);
//     }
//     cout<<rs;
// }
// int main(){
//         ios_base::sync_with_stdio(false);
//     cin.tie(0);   
//     ll n;
//     cin>>n;
//     vector<ll> arr(n,1);
//     for(ll i = 0 ; i < n ; i++){
//         cin>>arr[i];
//     }
//     ll rs=0,val;
//     for(ll i = 1 ; i < n ; i++){
//         if(arr[i]<arr[i-1]){
//             val= arr[i-1]-arr[i];
//             arr[i]+=val;
//             rs+=val;
//         }
//     }
//     cout<<rs;
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    ll n,t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>y>>x;
        ll rs;
        if(y>x){
            if(y%2==0){
                rs=y*y-x+1;
            }
            else{
                rs=(y-1)*(y-1)+x;
            }
        }
        else if(x>y){
            if(x%2!=0){
                rs=x*x-y+1;
            }
            else{
                rs=(x-1)*(x-1)+y;
            }
        }
        else if(x==y){
            if(x%2!=0){
                rs=x*x-y+1;
            }
            else if(y%2==0){
                rs=y*y-x+1;
            }
        }
        cout<<rs<<'\n';
    }
}