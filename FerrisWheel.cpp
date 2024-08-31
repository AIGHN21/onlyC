#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define el cout<<'/n'
#define fori for(ll i = 0 ; i < n ; i++)
#define fori1 for(ll i = 1 ; i < n ; i++)
#define arri cout<<arr[i]<<" "
#define ID "WangZhi"
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    fori{
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll rs = 0;
    ll start = 0 , end = n-1;
        while(start<=end){
            if(arr[start] + arr[end]<=x){
                start++;
                end--;
                rs++;
            }
            else if(arr[start] + arr[end]>x){
                end--;
                rs++;
            }
            else if(start == end ){
                rs++;
            }

        }
        
    cout<<rs;
       
    }


