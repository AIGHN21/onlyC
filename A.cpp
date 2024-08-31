#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);  
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        while(n>0){
            ans+=n%10;
            n=n/10;
        }
        cout<<ans<<"\n";
    }
    return 0;
    }