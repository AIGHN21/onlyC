#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

void Solve(ll prefixsum[]){
    ll a,b;
    cin>>a>>b;
    cout<<prefixsum[b-1]-prefixsum[a-1]<<ln;
}

int main(){
    IO
    string s;
    cin>>s;
    ll n = s.size();
    ll prefixsum[n]={0};
    for(ll i = 1 ; i < n ; i++){
        if(s[i]==s[i-1]){
            prefixsum[i]=prefixsum[i-1]+1;
        }
        else{
            prefixsum[i]=prefixsum[i-1];
        }
    }
    ll t;
    cin>>t;
  while(t--){
        Solve(prefixsum);
    }
    return 0;
}
