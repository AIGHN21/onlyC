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
ll bruteforce(ll value,ll current,vector<vector<ll>> arr,ll x){
    for (ll i = 0; i < 2; i++) {
        ll newValue = value + arr[current][i];
        if (newValue == x || current == arr.size() - 1) {
            return newValue;
        }
        ll result = bruteforce(newValue, current + 1, arr, x);
        if (result == x) {
            return result;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<vector<ll>> arr(n,vector<ll>(2));
    for(ll i = 0 ; i < n ; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    bool found = false;
    for(int i = 0 ; i < 2 ;i++){
        if(bruteforce(arr[0][i],1,arr,x)==x){
            cout<<"Yes";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No";
    }
    return 0;
    }



