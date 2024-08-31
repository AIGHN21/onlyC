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
    vector<ll> dp;

    for(int i = 0 ; i < n ; i++){
         auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) {
            dp.push_back(arr[i]);
        }
        else{
            dp[dp.size()-1] = arr[i];
        }
    }
    for(int i = 0 ; i < n ; i++){ 
       cout<<dp[i]<<" ";
    }
    cout<<dp.size();


   }