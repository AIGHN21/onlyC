#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define el '/n'
#define cinArr(arr,n) for(ll i = 0 ; i < n ; i++){cin >> arr[i];}
#define fori(start,n) for(ll i = start ; i < n ; i++)
#define arri cout<<arr[i]<<" "
#define ID "WangZhi"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> arr1(n), arr2(m),check(m);
    cinArr(arr1,n);
    cinArr(arr2,m);
    sort(arr1.begin(),arr1.end());
    // fori(0,n){
    //     cout<<arr1[i];
    // }
    fori(0,m){
        auto it = lower_bound(arr1.begin(),arr1.end(),arr2[i]);
        if(it- arr1.begin()<=n){
            ll pos = distance(arr1.begin(), it);
            if(arr1[pos]!=arr2[i]){
                pos--;
            }
            for(ll j = i ; )
            cout<<arr1[pos]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
    }
    
}


