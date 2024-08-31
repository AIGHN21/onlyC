#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
int countbitk(int vitrik,int n,int arr[]) {
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(isKthBitSet(arr[i],vitrik)){
            count++;
        }
    }
}
bool isKthBitSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    while(t--){
    vector<vector<int>> arr2(32,vector<int>(pow(10,5)));
    int l , r;
    cin>>l>>r;
        for(int k = 0 ; k < 32 ; k++){
            
        }
    }
}