#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;

int main(){
    IO
    int n ;
    cin >> n;
     double arr[n+1];
     for(int i = 1; i<= n;i++){
        cin>>arr[i];
     }
     double dpn[n+1],dps[n+1],dpsn[n+1];
     dpn[1]=arr[1];
     dps[1]=1 - arr[1];
     dpsn[1]=0;
     for(int i = 2 ; i<= n ;i++){
        dpn[i]=arr[i]*dpn[i-1];
        dps[i]=(1-arr[i])*dps[i-1];
        dpsn[i]=arr[i]*dps[i-1]+(1-arr[i])*dpn[i-1]+arr[i]*dpsn[i-1]+(1-arr[i])*dpsn[i-1];
        cout<<"dong xu thu "<<i<<ln;
        cout<<"dps"<<dps[i]<<ln;
        cout<<"dpn"<<dpn[i]<<ln;
        cout<<"sapngua"<<dpsn[i]<<ln;
        cout<<"dong xu thu "<<i<<" la "<<dpn[i]+dpsn[i]<<ln;
     }
    cout<<dpn[n]+dpsn[n];
    return 0;
}
