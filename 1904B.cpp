#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include <algorithm>
void Solve(){
    int n;
    cin>>n;
    unordered_map<long long , long long> mymap;
    vector<long long> arr(n),arrsort(n),sum(n),check(n);
    for(long long i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    arrsort = arr;
    sort(arrsort.begin(), arrsort.end());
    sum[0]=arrsort[0];
    for(int i = 1 ; i < n ; i++){
        sum[i] = arrsort[i]+sum[i-1];
        auto it = upper_bound(arrsort.begin(), arrsort.end(), sum[i]);
        // if (mymap.find(arrsort[i]) == mymap.end()) {
            mymap[arrsort[i]]=it-arrsort.begin()-1;
        // }
        
    }
    for(int i = 0 ; i < n ; i++){
        cout<<mymap[arr[i]]<<" ";
    }
    cout<<"\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}