#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#include<vector>
#include<unordered_map>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int n ,x;
    cin>>n>>x;
    vector<int> weight(n),values(n);
    unordered_map<int,int> myMap;
     for(int i = 0 ; i < n;i++){
       cin>>weight[i];
    }
    for(int i = 0 ; i < n;i++){
       cin>>values[i];
    }
    for(int i = 0 ; i < n ; i++){
        myMap[weight[i]]=values[i];
    }
    sort(weight.begin(),weight.end());
    ll dp[n+1][11]={0};
    for (int i = weight[0]; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (weight[j-1] <= i ) {
                dp[j][i] = max(dp[j-1][i], dp[j-1][i-weight[j-1]] + myMap[weight[j-1]]);
            } else if(weight[j-1] > i) {
                dp[j][i] = dp[j-1][i];
            }
        }
    }
    
        cout<<dp[n][x];
}