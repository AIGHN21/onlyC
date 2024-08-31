#include <bits/stdc++.h>
using namespace std;
void Solve(){
    int n,count = 0;
    cin>>n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<long long> suffixArray(n);
    suffixArray[0]=arr[0];
    long long maxV = arr[0];
    if(arr[0]==0){
        count++;
    }
    for(int i = 1 ; i < n ; i++){
        suffixArray[i]=suffixArray[i-1]+arr[i];
        maxV = max(maxV,arr[i]);
        if(suffixArray[i]/2==maxV && suffixArray[i]%2==0 ){
            count++;
        }
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}