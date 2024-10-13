#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;



int main(){
    IO
    ll t;
    vector<ll> arr(4);
    cin>>arr[1]>>arr[2]>>arr[3];
    ll x1,x2,x3;
    x3 = (arr[1]-(arr[2]-arr[3]))/2;
    x1 = arr[1] - x3;
    x2 = arr[2]-x1;
    if((x1>0 && x2>0 && x3>= 0 )|| (x1>=0 && x2>0 && x3> 0 )|| (x1>0 && x2>=0 && x3> 0 ) && (x1+x2+x3)%2==0){
            cout<<x1<<" "<<x2<<" "<<x3;
    }
    else{
        cout<<"Impossible";
    }
    return 0;
}
