#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void Solve(){
    int n,k;
    cin>>n>>k;
    ll arr[n];
    int dem = 0;
    ll MAX[2];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(arr[i]>arr[k-1]){
            MAX[dem]=i;
            dem++;
        }
    }
    if(dem == 2){
        if(k-1<MAX[0]){
        cout<<MAX[0]-1;
        }
        else if(k-1>MAX[0] && k-1 <MAX[1]){
        cout<<max(MAX[0]-1,k-1-MAX[0]);
        }  
        else if(k-1>MAX[1]){
         cout<<max(MAX[0]-1,MAX[1]-MAX[0]);
        }
    }
    else if(dem == 1){
        if(k-1<MAX[0]){
            cout<<MAX[0]-1;
        }
        else{
            if(n>2){
              cout<<max(MAX[0]-1,k-1-MAX[0]);  
            }
            else{
                cout<<0;
            }
            
        }
    }
    else{
        cout<<n-1;
    }
   cout<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}