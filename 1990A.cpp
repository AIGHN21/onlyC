#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#include<vector>
#include<unordered_map>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }
        bool flg = false;
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i]>arr[i+1]){
                if(i%2!=0 ){
                    cout<<"NO"<<endl;
                    flg = true;
                    break;
                }
                else if(i==0){
                    cout<<"YES"<<endl;
                    flg = true;
                    break;
                }
                else{
                    cout<<"YES"<<endl;
                    flg = true;
                    break;
                }
            }
        }
        if(flg == false){
            if((n-1)%2==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }

}
