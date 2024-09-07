#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define el cout<<'\n'
#define fori for(ll i = 0 ; i < n ; i++)
#define fori1 for(ll i = 1 ; i < n ; i++)
#define arri cout<<arr[i]<<" "
#define ID "Huunghia"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,a,b;
    cin >> n>>a>>b;
    vector<ll> arr(n),dp(n),dp2(n),prefixsum(n);
    
    fori {
        cin >> arr[i];
    }
    prefixsum[0]=arr[0];
    for(ll i = 1 ; i < n ; i++){
        prefixsum[i]=prefixsum[i-1]+arr[i];
    }
    for(ll i = a ; i < n )
    return 0;
}
