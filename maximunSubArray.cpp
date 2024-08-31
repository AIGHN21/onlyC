#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++){ 
        cin>>arr[i];
        }
    long long maxV = arr[0];
    for(int i = 1 ; i < n ; i++){
        arr[i] = max(arr[i],arr[i-1] + arr[i]);
        maxV = max(maxV,arr[i]);
    }
    cout<<maxV;
}