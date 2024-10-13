#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<unordered_map>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    IO
    int t; cin >>n;
    unordered_map<ll,ll> maps;
    vector<ll> arr(n+1);
    for(ll i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(ll i = 1 ; i <= n ; i++){
        maps[arr[i]]=i;
    }
    ll q;
    while(q--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll idxa = maps[a];
        ll idxb = maps[b];
        ll dp[n+1][k+1];
        dp[idxa][1]=1;
        for(ll i = idxa+1;i<idxb;i++){
            for(ll j = 2 ; j<=k;j++){

            }
        }
    }

    return 0;
}
