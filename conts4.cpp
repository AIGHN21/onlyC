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
    
    ll n;
    cin >> n;
    vector<ll> arr(n);
    
    fori {
        cin >> arr[i];
    }
    map<ll,ll> mymap;
    ll rs = 1;
    mymap[arr[0]]++;
    ll left = 0;
    for(ll i = 1 ; i < arr.size();i++){
        if(mymap[arr[i]]==0){
            rs++;
            mymap[arr[i]]++;
        }
        else{
            left++;
        }
    }
    cout<<arr.size()-left;
    return 0;
}
