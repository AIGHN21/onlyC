#include <bits/stdc++.h>
using namespace std;
void Solve(){
        int m,n;
        cin>>n>>m;
        if(n>=m && (n%2==m%2)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Solve();
    }
}