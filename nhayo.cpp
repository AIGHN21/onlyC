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
    int chan = 1;
    for(int i = 1 ; i < n ; i++){
        if(i%2!=0 && chan == 1){
            arr[i] = max(arr[i-1],arr[i]+arr[i-1]);
            chan = 0;
        }
        else if(i%2==0 && chan == 0){
            arr[i] = max(arr[i-1],arr[i]+arr[i-1]);
            chan = 1;
        }
        maxV = max(arr[i],maxV);
    }
    cout<<maxV;
}