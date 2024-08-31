#include<bits/stdc++.h>
using namespace std;
int checkHeight(vector<int> arr,int height, int checkHeight){
    int n = arr.size();
    int tong = n;
    
    // for(int  i = 0 ; i < n ; i++){
    //     if(i%2!=0){
    //         int freeSpace = height-arr[i];
    //         if(checkHeight<=freeSpace){
    //             tong--;
    //         }
    //     }
    //     else if(i==0 || i%2==0 ){
    //         if(checkHeight>arr[i]){
    //             tong--;
    //         }
    //     }
    // }
    return tong;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int min = INT_MAX;
    map<int,int> tansuat;
    int checkValue=0;
    for(int i = 1 ; i <= m ; i++){
        checkValue=checkHeight(arr,m,i);
        tansuat[checkValue]++;
       if(min>checkValue)
        min=checkValue;   
    }
    cout<<min<<" "<<tansuat[min];
}