#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void Solve(){
    ll x , y , k;
    cin>>x>>y>>k;
    while(k>0){
        ll temp = y - x%y;
        if(temp<=k){
        x+=temp;
        while(x%y==0){
            x/=y;
        }
            k -=temp;
        }
        else{
            x+=k;
            k = 0;
        }
        
    }
    cout<<x<<endl;
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