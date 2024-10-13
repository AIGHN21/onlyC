#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ln "\n"
using namespace std;
void Solve(){

}
int main(){
    ll n,m;
    cin>>n>>m;
    char arr[n+1][m+1];
    for(ll i = 1 ; i<= n ;i++){
        for(ll j = 1 ; j<= m ; j++){
            cin>>arr[i][j];
        }
    }
    ll prexC[n+1][m+1] , preR[n+1][m+1];
    for(ll i = 1 ; i<= n ;i++){
            prexC[i][1]=((arr[i][1]=='#')?1:0);
        for(ll j = 2 ; j<= m ; j++){
            if(arr[i][j]=='.'){
                prexC[i][j]=0;
            }
            else{
                 prexC[i][j]=1+prexC[i][j-1];
            }
        }
    }
     for(ll i = 1 ; i<= m ;i++){
            preR[1][i]=((arr[1][i]=='#')?1:0);
        for(ll j = 2 ; j<= n ; j++){
            if(arr[i][j]=='.'){
                preR[j][i]=0;
            }
            else{
                 preR[j][i]=1+preR[j-1][i];
            }
        }
    }
    for(ll i = 1 ; i<= n ;i++){
        for(ll j = 1 ; j<= m ; j++){
            cout<<prexC[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(ll i = 1 ; i<= m ;i++){
            preR[1][i]=((arr[1][i]=='#')?1:0);
        for(ll j = 1 ; j<= n ; j++){
           cout<<preR[i][j]<<" ";
        }
         cout<<"\n";
    }

}
