#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
#include<map>
using namespace std;
void Solve(){

}
int main(){
    IO
    ll n,d;
    cin>>n>>d;
    vector<ll>arr(n+1);
    vector<ll>dx(d+1);
    map<ll,ll> maps;
    for(ll i = 1; i<= n ;i++){
        cin>>arr[i];
        maps[arr[i]]=i;
    }
    for(ll i = 1; i<= d;i++){
        dx[i]=arr[i];
    }
    ll ans = 0;
    for(ll i = d+1; i<= n ;i++){
//        sort(dx.begin(),dx.end());
        double tv;
        if (d % 2 == 0) {
            tv = (dx[d / 2] + dx[d / 2+1]) / 2.0;
        } else {
            tv = dx[d / 2+1];
        }
        if(arr[i]>=2*tv){
            ans++;
        }
        auto it = lower_bound(dx.begin(),dx.end(),arr[i-d]);
        if(*it == arr[i-d] &&it != dx.end()){
            dx.erase(it);
        }
        dx.push_back(arr[i]);

    }
    cout<<ans;
    return 0;
}
