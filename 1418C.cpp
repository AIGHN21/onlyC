#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
void Solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n+1);
    for(ll i = 1; i<= n ;i++){
        cin>>arr[i];
    }
    ll ans = 0;
    ll sc = 1;
    for( ll i = 1 ; i<= n ; i++){
        if(sc==1){
            if(arr[i]==1){
                ans++;
            }
            sc++;
        }
        else{
            if(arr[i]==0){
                i+=2;
            }
            else{
                i+=1;
            }
            sc = 1;
        }
    }
    cout<<ans<<ln;
}
int main(){
    IO
    int t; cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
