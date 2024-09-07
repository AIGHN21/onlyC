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
    
    ll n,m;
    cin >> n >> m;
    vector<ll> arr(n),arr2(m);
    
    fori {
        cin >> arr[i];
    }
    for(ll i  = 0 ; i < m ; i++){
        cin>>arr2[i];
    }
    // sort(arr.begin(),arr.end());
    map<ll,ll> mymap;
    vector<ll> queuelist;
    
    fori{
        auto it = upper_bound(queuelist.begin(),queuelist.end(),arr[i]);
         if(it!=queuelist.end()){
            queuelist.insert(it,arr[i]); 
            ll pos = it-queuelist.begin();
            mymap[pos]=i;
        }
        else{
            queuelist.push_back(arr[i]);
            mymap[queuelist.size()]=i;
        }
       
    } 
   fori{
        cout<<queuelist[i]<<" ";
   }
   cout<<endl;
for(ll i = 0 ; i < queuelist.size() ; i++){
            cout<<mymap[i]<<" ";
        }
    return 0;
}
