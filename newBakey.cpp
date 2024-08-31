#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        long long tong = 0;
        if(a<b){
        int k = b - a;
            if(k<n){
                for(int i = 1 ; i<=k ; i++){
                tong+=i+a;
                } 
                tong+=a*(n-k);
            }
            else{
            for(int i = 1 ; i<=n ; i++){
                tong+=(b- i+1);
            } 
            }
        }
        else{
            tong=a*n;
        }
        cout<<tong<<endl;
    }
}