#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
typedef long long ll;
int minV(int arr[],int l , int r){
    int mid = (r + l)/2;
    if(mid==l){
        return min(arr[l],arr[r]);
    }
    int leftM = minV(arr,l,mid);
    int rightM = minV(arr,mid+1,r);
    return min(leftM,rightM);
}
int main(){
    int arr[8]={7,2,3,5,9,4};
    cout<<minV(arr,0,3);
}
