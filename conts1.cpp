#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define el cout<<'/n'
#define fori for(ll i = 0 ; i < n ; i++)
#define fori1 for(ll i = 1 ; i < n ; i++)
#define arri cout<<arr[i]<<" "
#define ID "Huunghia"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    vector<vector<ll>> arr(n,vector<ll>(2));
    for(ll i = 0 ; i < n ; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    sort(arr.begin(),arr.end());
    for(ll i = 0 ; i<n ; i++){
        
    }
    return 0;
    }



